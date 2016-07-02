#include "fss.h"
#include <cmath>
#include <limits>

FSS::FSS(int fishAmount, int dim, int epoch, AlgorithmFactory::ALGORITHM alg)
{
    this->epoch = epoch;
    this->dimensions = dim;

    AlgorithmFactory af(alg);
    this->alg = af.get();
    this->alg->init(this->min, this->max);

    this->initializeFish(fishAmount);

    this->stepSize = 10;
    this->lastW = 0;
    this->bestFit = std::numeric_limits<double>::max();
}

/**
 * @brief FSS::~FSS
 *
 * Destrutor
 */
FSS::~FSS()
{
    for(int i=0, size = this->fishes->size(); i<size; ++i)
    {
        delete this->fishes->at(i);
    }
    delete this->fishes;
    delete this->alg;
}

#include <iostream>
std::vector<double>* FSS::work()
{
    std::vector<double>* fits = new std::vector<double>();
    for(int i=0; i<epoch; ++i)
    {
        this->step();
        fits->push_back(this->bestFit);
        if(i%200 == 0)
            std::cout << "passo: " << i << std::endl;
    }
    return fits;
}

void FSS::step()
{
    for(Fish* f : *fishes)
    {
        individualMovement(f);//movimento individual no caso de melhoria do fitness
    }
    double maxDeltaF = 0;
    this->getMaxDelta(maxDeltaF);

    double botDeltaF = 0;
    for(Fish* f : *fishes)
    {
        feeding(f, maxDeltaF);
        if(f->getDeltaF() != 0) //só há deltaX se houver deltaF
        {
            botDeltaF += f->getDeltaF();
        }
    }
    std::vector<double> upVec(this->dimensions, 0.0);
    for(Fish *f : *fishes)
    {
        if(f->getDeltaF() != 0)
        {
            std::vector<double>* v = f->getData();
            for(int i=0; i<dimensions; ++i)
            {
                upVec.at(i) = v->at(i)*botDeltaF;
            }
        }
    }
    if(botDeltaF!=0)
        for(int i=0; i<dimensions; ++i)
            upVec.at(i) /= botDeltaF;


    for(Fish *f : *fishes)
    {
        instinctiveMovement(f, upVec);
    }
    double totalW;
    std::vector<double>* bar = barycentre(totalW);

    for(Fish *f : *fishes)
    {
        volitiveMovement(f, totalW > lastW, bar);
        double fit = alg->fitness(f->getData());
        this->bestFit = fit < bestFit ? fit : bestFit;
        f->setFitness(fit);
    }
    delete bar;
    updateStep();
}

/**
 * @brief FSS::initializeFish
 * @param size quantidade de peixes
 *
 * inicializa os peixes aleatoriamente
 */
void FSS::initializeFish(int size)
{
    this->fishes = new std::vector<Fish*>();
    for(int i=0; i<size; ++i)
    {
        Fish* f = new Fish(this->dimensions);
        for(int j=0; j<this->dimensions; ++j)
        {
            double ran = this->getRandom(min, max);
            f->setData(j, ran);
        }
        f->setFitness(this->alg->fitness(f->getData()));
        this->fishes->push_back(f);
    }
}

void FSS::individualMovement(Fish *f)
{
    std::vector<double>* xVec = f->cloneData();
    for(int i=0; i<dimensions; ++i)
    {
        xVec->at(i) += this->getRandom(-1, 1) * this->stepSize;
    }
    double fit = alg->fitness(xVec);
    if(fit < f->getFitness())
    {
        f->setData(xVec);
        f->setFitness(fit);
    }
    else
    {
        f->resetDelta();
        delete xVec;
    }
}

void FSS::getMaxDelta(double &maxF)
{
    for(Fish*f : *fishes)
    {
        double delta = f->getDeltaF();
        if(std::abs(delta)>std::abs(maxF))
            maxF = delta;
    }
}

void FSS::feeding(Fish* f, double maxDeltaF)
{
    if(maxDeltaF != 0)
    {
        f->setWeight(f->getWeight() + std::abs(f->getDeltaF()/maxDeltaF));
    }
}

void FSS::instinctiveMovement(Fish* f, std::vector<double> v)
{
    std::vector<double>* temp = new std::vector<double>(f->getData()->begin(), f->getData()->end());
    for(int i=0; i<dimensions; ++i)
    {
        temp->at(i) =  temp->at(i) + v.at(i);//x(t) + m(t)
    }
    double fit = alg->fitness(temp);
    if(fit < f->getFitness())
    {
        f->setFitness(fit);
        f->setData(temp);
    }
    else
    {
        delete temp;
    }
}

std::vector<double>* FSS::barycentre(double &total)
{
    std::vector<double>* b = new std::vector<double>(dimensions, 0.0);
    std::vector<double> top(dimensions, 0);
    total = 0;
    for(Fish* f: *fishes)
    {
        total += f->getWeight();
        for(int i=0; i<dimensions; ++i)
        {
            top.at(i) += f->getData(i) * f->getWeight();
        }
    }
    if(total!=0)
    {
        for(int i=0; i<dimensions; ++i)
            b->at(i) = top.at(i)/total;
    }
    return b;
}

void FSS::volitiveMovement(Fish *f, bool increased, std::vector<double>* b)
{
    //se o peso aumentou, o movimento será de agrupamento (negativo)
    int k = increased ? -1 : 1;
    double dist = this->euclideanDistance(f->getData(), b);
    for(int i=0; i<dimensions; ++i)
    {
        double rand = this->getRandom() * k;
        double stepVol = 2*this->stepSize;
        double x = f->getData(i);
        double diff = x - b->at(i);

        f->setData(i, x + (stepVol * rand * (diff/dist)));
    }
}

void FSS::updateStep()
{
    this->stepSize *= 0.99;
}

#include "randutils.hpp"
double FSS::getRandom(double min, double max)
{
    randutils::mt19937_rng rng;

    return rng.uniform(min, max);
}

double FSS::euclideanDistance(std::vector<double> *a, std::vector<double> *b)
{
    double dist = 0;
    for(int i=0, size=a->size(); i<size; ++i)
    {
        dist += std::pow((b->at(i)-a->at(i)), 2);
    }
    return std::sqrt(dist);
}
