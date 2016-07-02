#include "aco.h"

#include "tspreader.h"
#include <climits>

#include <iostream>
#include <cmath>

ACO::ACO(double alpha, double beta, int pheromoneQ, double pheromoneRho, std::string fileOpen, bool useOnlyQ, int pushNum)
{
    this->alpha = alpha;
    this->beta = beta;
    this->pheromoneQ = pheromoneQ;
    this->pheromoneRho = pheromoneRho;
    this->pushNum = pushNum;

    this->useQ = useOnlyQ;
    TSPReader tspr(fileOpen);
    this->ground = new Ground();
    ground->createCities(tspr.getPositions());

    //de acordo com o pedido pelo trabalho
    this->createAnts(this->ground->size()*2);
}

ACO::~ACO()
{
    delete this->ground;
    delete this->ants;
}

std::vector<int> ACO::run(int epoch)
{
    //http://comopt.ifi.uni-heidelberg.de/software/TSPLIB95/STSP.html optimum
    //att48 = 10628 <<<< melhor possível
    std::vector<int> distances;
    for(int i=0; i<epoch; ++i)
    {
        //anda
        int lowest = this->walk();
        if(i%pushNum == 0)
        {
            distances.push_back(lowest);
            std::cout << i << " >> Menor caminho: " << lowest << std::endl;
        }
    }
    return distances;
}

void ACO::createAnts(int amount)
{
    this->ants = new std::vector<Ant*>();
    for(int i=0; i<amount; ++i)
    {
        Ant* ant = new Ant();
        this->ants->push_back(ant);
    }
}

int ACO::walk()
{
    //faz as formigas esquecerem que já visitaram uma cidade
    this->resetAnts();
    //move todas as formigas
    for(auto& ant : *this->ants)
    {
        this->antStep(ant);
    }
    //todas andaram
    this->putPheromone();

    //pega o menor caminho
    return this->lowestPath();
}

void ACO::antStep(Ant *ant)
{
    //para todas as cidades
    for(int i=0, size = this->ground->size(); i<size; ++i)
    {
        if(ant->getVisited().size()==this->ground->size())
        {
            ant->popFirst();//assim faz o caminho de volta ao primeiro
        }
        std::vector<double> path;
        int last = ant->getLast();

        //somatorio de "tao" e "eta" das cidades a serem visitadas pela formiga
        double otherInfluence = 0;
        for(int k=0; k<size;++k)
        {
            if(ant->hasVisited(k))
            {
                continue;
            }
            else
            {
                Path* toGo = this->ground->at(last, k);
                otherInfluence+=toGo->getInfluence(alpha, beta);
            }
        }

        for(int j=0; j<size; ++j)
        {
            if(ant->hasVisited(j))
            {
                path.push_back(0);
                continue;
            }

            Path* p = this->ground->at(last,j);
            double pInfluence = p->getInfluence(this->alpha, this->beta);

            double prob = pInfluence/otherInfluence;
            path.push_back(prob);
        }

        int pos = this->roulette(path);
        ant->addCity(pos);
        Path* p = this->ground->at(last,pos);
        ant->addDistance(p->getDistance());
    }
}

void ACO::resetAnts()
{
    for(Ant* ant : *this->ants)
    {
        ant->clearVisited();
        ant->addCity(0);
    }
}

void ACO::putPheromone()
{
    double sum=0;
    for(Ant* ant : *this->ants)
    {
        if(useQ)
        {
            sum += pheromoneQ;
        }
        else
        {
            sum += pheromoneQ/(double)ant->getDistance();
        }

    }
    int last = 0;
    for (int i = 0, size=this->ants->size(); i < size; ++i)
    {
        Ant* ant = this->ants->at(i);
        for(int j=0, pSize=ant->getVisited().size(); j<pSize; ++j)
        {
            int now = ant->getVisited().at(j);
            Path *p = this->ground->at(last, now);
            double pheromone = p->getPheromone();
            pheromone += sum;

            p->setPheromone(pheromone);

            this->ground->at(now, last)->setPheromone(pheromone);
            last = now;
        }
        last = 0;
    }
    for(int i=0, size=this->ground->size(); i<size; ++i)
    {
        for(int j=0; j<size; ++j)
        {
            Path *p = this->ground->at(i,j);
            p->setPheromone(p->getPheromone()* (1-pheromoneRho));
        }
    }
}

int ACO::lowestPath()
{
    int lowestDist = INT_MAX;
    for(auto& ant : *this->ants)
    {
        if(ant->getDistance()<lowestDist)
            lowestDist = ant->getDistance();
    }
    return lowestDist;
}

#include "randutils.hpp"
//http://programadoraprendendo.blogspot.com.br/2012/12/algoritmos-de-selecao-metodo-da-roleta.html
int ACO::roulette(std::vector<double> &vec)
{
    /*double values = 0;
    for(double& v : vec)
    {
    values += v;
    }*/
    randutils::mt19937_rng rng;

    double random = rng.uniform(0.0, 1.0);
    random = random;//*values;//achei o valor dada a porcentagem
    int position = -1;
    do
    {
        position++;
        random -= vec.at(position);
    }
    while(random>0);

    return position;
}
