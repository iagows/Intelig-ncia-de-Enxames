#include "bee.h"

Bee::Bee(int size)
{
    this->data = new std::vector<double>(size);
    this->trial = 0;
}

Bee::~Bee()
{
    delete this->data;
}

void Bee::setData(int i, double val)
{
    this->data->at(i) = val;
}

double Bee::getData(int i)
{
    return this->data->at(i);
}

std::vector<double> *Bee::cloneData()
{
    return new std::vector<double>(this->data->begin(), this->data->end());
}

double Bee::getFitness()
{
    return this->fitness;
}

void Bee::setFitness(double val)
{
    this->fitness = val;
}
