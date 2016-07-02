#include "path.h"

#include <climits>
#include <cmath>

Path::Path()
{
    this->distance = INT_MAX;
    this->pheromone = 1./48;
}

void Path::setDistance(int d)
{
    this->distance = d;
}

int Path::getDistance()
{
    return this->distance;
}

void Path::setPheromone(double p)
{
    this->pheromone = p;
    if(p<0) p = 1./48;//nada de negativo aqui
}

double Path::getPheromone()
{
    return this->pheromone;
}

double Path::getInfluence(double alpha, double beta)
{
    double tao = std::pow(this->pheromone, alpha);
    double eta = std::pow(1./this->distance, beta);

    return tao*eta;
}
