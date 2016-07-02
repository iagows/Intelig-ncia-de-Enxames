#ifndef ALGORITHMSPHERE_H
#define ALGORITHMSPHERE_H

#include "algorithms/abstracttestalgorithm.h"
class AlgorithmSphere : public AbstractTestAlgorithm
{
public:
    AlgorithmSphere();
    ~AlgorithmSphere() override;

    void init(double &min, double &max, double &vMax) override;
    double fitness(Particle *part, int dimensions) override;

    virtual double getInitialBest() const override;
};

#endif // ALGORITHMSPHERE_H
