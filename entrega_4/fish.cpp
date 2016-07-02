#include "fish.h"

#include <cinttypes>

Fish::Fish(int size)
{
    this->data = new std::vector<double>(size);
    this->maxW = 100;
    this->setWeight(3);
    this->fitness = INT32_MAX;

    this->deltaF = 0;
    this->deltaX = new std::vector<double>(size, 0.0);
}

Fish::~Fish()
{
    delete this->data;

    delete this->deltaX;
}

void Fish::setData(int i, double val)
{
    this->data->at(i) = val;
}

double Fish::getData(int i)
{
    return this->data->at(i);
}

std::vector<double> *Fish::getData()
{
    return this->data;
}

void Fish::setData(std::vector<double>* v)
{
    for(int i=0, size = v->size(); i<size; ++i)
    {
        this->deltaX->at(i) = v->at(i) - this->data->at(i);
    }

    delete this->data;
    this->data = v;
}

std::vector<double> *Fish::cloneData()
{
    return new std::vector<double>(this->data->begin(), this->data->end());
}

double Fish::getFitness()
{
    return this->fitness;
}

void Fish::setFitness(double val)
{
    this->deltaF = val - fitness;
    this->fitness = val;
}

double Fish::getWeight()
{
    return this->weight;
}

void Fish::setWeight(double d)
{
    if((d > 1 ) && (d < maxW))
        this->weight = d;
}

std::vector<double>* Fish::getDeltaX()
{
    return this->deltaX;
}

double Fish::getDeltaF()
{
    return this->deltaF;
}

void Fish::resetDelta()
{
    this->deltaF = 0;
    delete this->deltaX;
    this->deltaX = new std::vector<double>(this->data->size(), 0.0);
}
