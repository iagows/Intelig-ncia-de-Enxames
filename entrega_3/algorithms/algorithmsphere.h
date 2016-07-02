#ifndef ALGORITHMSPHERE_H
#define ALGORITHMSPHERE_H

#include "algorithms/abstracttestalgorithm.h"
class AlgorithmSphere : public AbstractTestAlgorithm
{
public:
    AlgorithmSphere();
    ~AlgorithmSphere() override;

    void init(double &min, double &max) override;
    double fitness(Bee *bee, int dimensions) override;

    virtual double getInitialBest() const override;
};

#endif // ALGORITHMSPHERE_H
