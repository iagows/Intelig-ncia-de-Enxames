#include "algorithmrotatedrastrigin.h"

#include <math.h>

AlgorithmRotatedRastrigin::AlgorithmRotatedRastrigin()
    :AbstractTestAlgorithm()
{

}

AlgorithmRotatedRastrigin::~AlgorithmRotatedRastrigin()
{

}

void AlgorithmRotatedRastrigin::init(double &min, double &max)
{
    this->max = 5;
    this->min = -this->max;

    max = this->max;
    min = this->min;
}

//http://www.sfu.ca/~ssurjano/rastr.html
#define PI 3.14159265
double AlgorithmRotatedRastrigin::fitness(Bee *bee, int dimensions)
{
    double out = 10 * dimensions;
    int count = dimensions;
    for(int i=0; i< count; ++i)
    {
        double di = bee->getData(i);
        if(!this->isInSpace(di))
        {
            out = INT32_MAX;
            break;
        }
        out += pow(di,2) - (10 *(cos(2*PI*di)));
    }
    return out;
}

double AlgorithmRotatedRastrigin::getInitialBest() const
{
    return 5; //pbest inicial de cada particula (se quer max, colocar min e vice-versa)
}
