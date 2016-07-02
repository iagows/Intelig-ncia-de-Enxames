#include "algorithmsphere.h"

AlgorithmSphere::AlgorithmSphere() :AbstractTestAlgorithm()
{

}

AlgorithmSphere::~AlgorithmSphere()
{

}

void AlgorithmSphere::init(double &min, double &max)
{
    this->max = 100;
    this->min = -this->max;

    min = this->min;
    max = this->max;
}

double AlgorithmSphere::fitness(Bee *bee, int dimensions)
{
    double calculatedFitness = 0;
    int count = dimensions;
    for(int i=0; i<count; ++i)
    {
        double d = bee->getData(i);
        if(!isInSpace(d))
        {
            calculatedFitness = INT32_MAX;
            break;
        }
        calculatedFitness += d*d;
    }
    return calculatedFitness;
}

double AlgorithmSphere::getInitialBest() const
{
    return 100; //pbest inicial de cada particula (se quer max, colocar min e vice-versa)
}
