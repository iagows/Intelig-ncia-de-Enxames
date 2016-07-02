#ifndef ALGORITHMROTATEDRASTRIGIN_H
#define ALGORITHMROTATEDRASTRIGIN_H

#include "algorithms/abstracttestalgorithm.h"
class AlgorithmRotatedRastrigin : public AbstractTestAlgorithm
{
public:
    AlgorithmRotatedRastrigin();
    ~AlgorithmRotatedRastrigin() override;
    void init(double &min, double &max) override;
    double fitness(Bee *bee, int dimensions) override;

    double getInitialBest() const override;
};

#endif // ALGORITHMROTATEDRASTRIGIN_H
