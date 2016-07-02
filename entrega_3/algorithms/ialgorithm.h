#ifndef IALGORITHM_H
#define IALGORITHM_H

#include "bee.h"

class IAlgorithm
{
public:
    IAlgorithm() { }
    virtual ~IAlgorithm() { }

    virtual void init(double &min, double &max)=0;
    virtual double fitness(Bee *bee, int dimensions)=0;

    virtual double getInitialBest() const = 0;

protected:
    virtual bool isInSpace(double d)=0;
};

#endif // IALGORITHM_H
