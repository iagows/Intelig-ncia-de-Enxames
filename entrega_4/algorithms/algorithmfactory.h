#ifndef ALGORITHMFACTORY_H
#define ALGORITHMFACTORY_H

#include "algorithms/algorithmsphere.h"
#include "algorithms/algorithmrosenbrock.h"
#include "algorithms/algorithmrotatedrastrigin.h"

class AlgorithmFactory
{
public:
    enum ALGORITHM
    {
        SPHERE,
        ROTATED_RASTRIGIN,
        ROSENBROCK
    };

    AlgorithmFactory(ALGORITHM alg);
    ~AlgorithmFactory();
    IAlgorithm *get() const;

private:
    IAlgorithm *algorithm;
};

#endif // ALGORITHMFACTORY_H
