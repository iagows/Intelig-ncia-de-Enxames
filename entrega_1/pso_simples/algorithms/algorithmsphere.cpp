#include "algorithmsphere.h"

AlgorithmSphere::AlgorithmSphere() :AbstractTestAlgorithm()
{

}

AlgorithmSphere::~AlgorithmSphere()
{

}

void AlgorithmSphere::init(double &min, double &max, double &vMax)
{
    this->max = 100;
    this->min = -this->max;
    this->vMax = 2*this->max;

    min = this->min;
    max = this->max;
    vMax = this->vMax;//0.1 aproxima muito mais na esfera
}

double AlgorithmSphere::fitness(Particle *part, int dimensions)
{
    double calculatedFitness = 0;
    int count = dimensions;
    for(int i=0; i<count; ++i)
    {
        double d = part->getData(i);
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
