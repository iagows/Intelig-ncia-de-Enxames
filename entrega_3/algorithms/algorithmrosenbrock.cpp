#include "algorithmrosenbrock.h"

#include <math.h>
AlgorithmRosenbrock::AlgorithmRosenbrock()
    :AbstractTestAlgorithm()
{

}

AlgorithmRosenbrock::~AlgorithmRosenbrock()
{

}

void AlgorithmRosenbrock::init(double &min, double &max)
{
    this->max = 100;
    this->min = -this->max;

    min = this->min;
    max = this->max;
}

double AlgorithmRosenbrock::fitness(Bee *bee, int dimensions)
{
    double out = 0;
    int count = dimensions-1;
    for(int i =0; i< count; ++i)
    {
        double di = bee->getData(i);
        if(!isInSpace(di))
        {
            out = INT32_MAX;
            break;
        }
        double di2 = bee->getData(i+1);

        out += (100*pow((di2 - (di*di)), 2)) + pow((di-1),2);
    }
    return out;
}

double AlgorithmRosenbrock::getInitialBest() const
{
    return 32; //pbest inicial de cada particula (se quer max, colocar min e vice-versa)
}
