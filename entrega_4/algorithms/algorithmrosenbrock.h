#ifndef ALGORITHMROSENBROCK_H
#define ALGORITHMROSENBROCK_H

#include "algorithms/abstracttestalgorithm.h"
class AlgorithmRosenbrock:public AbstractTestAlgorithm
{
public:
    AlgorithmRosenbrock();
    ~AlgorithmRosenbrock() override;
    void init(double &min, double &max) override;
    double fitness(std::vector<double>* data) override;

    virtual double getInitialBest() const override;
};

#endif // ALGORITHMROSENBROCK_H
