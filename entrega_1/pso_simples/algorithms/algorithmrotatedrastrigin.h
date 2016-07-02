#ifndef ALGORITHMROTATEDRASTRIGIN_H
#define ALGORITHMROTATEDRASTRIGIN_H

#include "algorithms/abstracttestalgorithm.h"
class AlgorithmRotatedRastrigin : public AbstractTestAlgorithm
{
public:
    AlgorithmRotatedRastrigin();
    ~AlgorithmRotatedRastrigin() override;
    void init(double &min, double &max, double &vMax) override;
    double fitness(Particle *part, int dimensions) override;

    double getInitialBest() const override;
};

#endif // ALGORITHMROTATEDRASTRIGIN_H
