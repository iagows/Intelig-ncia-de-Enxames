#ifndef ALGORITHMSPHERE_H
#define ALGORITHMSPHERE_H

#include "algorithms/abstracttestalgorithm.h"
class AlgorithmSphere : public AbstractTestAlgorithm
{
public:
    AlgorithmSphere();
    ~AlgorithmSphere() override;

    void init(double &min, double &max) override;
    double fitness(std::vector<double> *data) override;

    virtual double getInitialBest() const override;
};

#endif // ALGORITHMSPHERE_H
