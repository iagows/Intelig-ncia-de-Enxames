#include "particle.h"

Particle::Particle(int dataSize, int defaultValue)
{
    this->data = new std::vector<double>(dataSize, defaultValue);
    this->pBest = nullptr;
    this->velocity = new std::vector<double>(dataSize, 2);
    this->fitness = RAND_MAX; //pior situação possível
}

Particle::~Particle()
{
    delete this->data;
    delete this->pBest;
    delete this->velocity;
}

double Particle::getData(double pos) const
{
    return this->data->at(pos);
}

std::vector<double> *Particle::getData() const
{
    return this->data;
}

void Particle::setData(int pos, double value)
{
    this->data->at(pos) = value;
}

void Particle::setPBest(std::vector<double> *pb)
{
    this->pBest = new std::vector<double>(pb->begin(), pb->end());
}

double Particle::getPBest(int pos)
{
    return this->pBest->at(pos);
}

std::vector<double> *Particle::getPBest()
{
    return this->pBest;
}

void Particle::setGBest(std::vector<double> *gb)
{
    this->gBest = gb;
}

std::vector<double> *Particle::getGBest() const
{
    return this->gBest;
}

double Particle::getVelocity(int pos) const
{
    return this->velocity->at(pos);
}

void Particle::setVelocity(int pos, double value)
{
    this->velocity->at(pos) = value;
}

double Particle::getFitness() const
{
    return this->fitness;
}

void Particle::setFitness(double val)
{
    this->fitness = val;
}
