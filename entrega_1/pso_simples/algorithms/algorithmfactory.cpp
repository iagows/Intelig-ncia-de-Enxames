#include "algorithmfactory.h"

AlgorithmFactory::AlgorithmFactory(ALGORITHM alg)
{
    this->algorithm = nullptr;
    switch (alg) {
    default:
    case ALGORITHM::SPHERE:
        this->algorithm = new AlgorithmSphere();
        break;
    case ALGORITHM::ROTATED_RASTRIGIN:
        this->algorithm = new AlgorithmRotatedRastrigin();
        break;
    case ALGORITHM::ROSENBROCK:
        this->algorithm = new AlgorithmRosenbrock();
        break;
    }
}

AlgorithmFactory::~AlgorithmFactory()
{

}

IAlgorithm *AlgorithmFactory::get() const
{
    return this->algorithm;
}
