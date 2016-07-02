#ifndef ABSTRACTTESTALGORITHM_H
#define ABSTRACTTESTALGORITHM_H

#include "algorithms/ialgorithm.h"
#include <stdint.h>

class AbstractTestAlgorithm : public IAlgorithm
{
public:
    AbstractTestAlgorithm();
    virtual ~AbstractTestAlgorithm() override;

    virtual void init(double &min, double &max)=0;
    virtual double fitness(std::vector<double>* data)=0;

    virtual double getInitialBest() const = 0;

protected:
    virtual bool isInSpace(double d) override;

    double max;
    double min;
};

#endif // ABSTRACTTESTALGORITHM_H
