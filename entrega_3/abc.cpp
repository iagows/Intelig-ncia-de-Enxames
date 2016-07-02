#include "abc.h"

#include <iostream>
#include "randutils.hpp"

ABC::ABC(int colSize, int initBN, int initBE, int dim, int maxEpoch, AlgorithmFactory::ALGORITHM alg)
{
    this->maxEpoch = maxEpoch;
    this->CS = colSize;
    this->BN = initBN;
    this->FS = this->BN;
    this->BC = this->CS - this->BN;
    this->BE = initBE;
    this->dimensions = dim;

    this->lim = (this->CS*this->dimensions)/2;

    AlgorithmFactory af(alg);
    this->alg = af.get();
    this->bestFitness = INT32_MAX;
}

ABC::~ABC()
{
    for(int i=0, size = this->colony->size(); i<size; ++i)
    {
        Bee* b = colony->at(i);
        delete b;
    }
    delete this->colony;

    for(int i=0, size = this->finders->size(); i<size; ++i)
    {
        Bee* b = finders->at(i);
        delete b;
    }
    delete this->finders;

    for(int i=0, size = this->followers->size(); i<size; ++i)
    {
        Bee* b = followers->at(i);
        delete b;
    }
    delete this->followers;

    delete this->alg;
}

void ABC::initialize()
{
    this->alg->init(min, max);
    this->createFoodSources();
    this->createColony();
    this->createFollowers();
}

std::vector<double> *ABC::search()
{
    std::vector<double> *out = new std::vector<double>();
    for(int i=0; i< maxEpoch; ++i)
    {
        step();
        out->push_back(this->bestFitness);
        if(i%200 == 0)
            std::cout << "Step: " << i << "\t\tfitness: " << this->bestFitness << std::endl;
    }
    return out;
}

double ABC::getBestFitness()
{
    return this->bestFitness;
}

void ABC::createColony()
{
    this->colony = new std::vector<Bee*>();
    for(int i=0; i<this->BN; ++i)
    {
        Bee* b = new Bee(this->dimensions);
        for(int j=0; j<this->dimensions; ++j)
        {
            double rand = this->getRandom(this->min, this->max);
            b->setData(j, rand);
        }
        b->setFitness(this->alg->fitness(b, this->dimensions));
        this->colony->push_back(b);
    }
}

void ABC::createFollowers()
{
    this->followers = new std::vector<Bee*>();
    for(int i=0; i<this->BC; ++i)
    {
        Bee* b = new Bee(this->dimensions);
        for(int j=0; j<this->dimensions; ++j)
        {
            double rand = this->getRandom(this->min, this->max);
            b->setData(j, rand);
        }
        b->setFitness(this->alg->fitness(b, this->dimensions));
        this->followers->push_back(b);
    }
}

void ABC::createFoodSources()
{
    this->finders = new std::vector<Bee*>();
    for(int i=0; i<this->FS; ++i)
    {
        Bee* bee = new Bee(this->dimensions);
        for(int j=0; j<this->dimensions; ++j)
        {
            bee->setData(j, getRandom(this->min, this->max));
        }
        double fit = this->alg->fitness(bee, this->dimensions);
        this->setBestFitness(fit);
        bee->setFitness(fit);
        this->finders->push_back(bee);
    }
}

double ABC::getRandom(double min, double max)
{
    randutils::mt19937_rng rng;

    return rng.uniform(min, max);
}

/**
  * Retorna true se o fit for melhor
  **/
void ABC::setBestFitness(double fit)
{
    if(fit < this->bestFitness)
    {
        this->bestFitness = fit;
    }
}

void ABC::step()
{
    double totalFit=0;
    std::vector<double> vec;
    for(int i=0; i<this->BN; ++i)
    {
        Bee* bee = this->colony->at(i);

        Bee* fakeBee = new Bee(this->dimensions);
        for(int j=0; j<this->dimensions; ++j)
        {
            double xij = bee->getData(j);
            int k = getRandom(0, this->BN);
            Bee* randomBee = this->colony->at(k);
            double xkj = randomBee->getData(j);
            double phi = getRandom(-1, 1);

            double vij = xij + (phi*(xij - xkj));
            fakeBee->setData(j, vij);
        }
        //fez um vetor de velocidade
        double tempFit = alg->fitness(fakeBee, this->dimensions);
        this->setBestFitness(tempFit);
        if(tempFit < bee->getFitness())
        {
            fakeBee->trial = 0;
            fakeBee->setFitness(tempFit);
            this->colony->at(i) = fakeBee;
            delete bee;
        }
        else
        {
            this->colony->at(i)->trial++;
        }
        tempFit = 1/(1+this->colony->at(i)->getFitness());//menores valores ganham prioridade
        vec.push_back(tempFit);
        totalFit += tempFit;
    }
    //prob individual
    for(int i=0, size=vec.size(); i<size; ++i)
    {
        vec.at(i) = (vec.at(i)/totalFit);
    }

    //todas andaram
    //agora uso a roleta pra ver quem tem mais influência
    for(int i=0; i< this->BN; ++i)
    {
        Bee*b = this->followers->at(i);
        int val = this->roulette(vec);
        Bee *randomBee = this->colony->at(val);
    }
}

int ABC::roulette(std::vector<double> &vec)
{
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
