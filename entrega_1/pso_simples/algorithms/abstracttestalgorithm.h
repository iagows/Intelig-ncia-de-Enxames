#ifndef ABSTRACTTESTALGORITHM_H
#define ABSTRACTTESTALGORITHM_H

#include "ialgorithm.h"

class AbstractTestAlgorithm : public IAlgorithm
{
public:
    AbstractTestAlgorithm();
    virtual ~AbstractTestAlgorithm() override;

    virtual void init(double &min, double &max, double &vMax)=0;
    virtual double fitness(Particle *part, int dimensions)=0;

    virtual double getInitialBest() const = 0;

protected:
    virtual bool isInSpace(double d) override;

    double max;
    double min;
    double vMax;
};

#endif // ABSTRACTTESTALGORITHM_H
