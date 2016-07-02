#ifndef IALGORITHM_H
#define IALGORITHM_H

#include "particle.h"

class IAlgorithm
{
public:
    IAlgorithm() { }
    virtual ~IAlgorithm() { }

    virtual void init(double &min, double &max, double &vMax)=0;
    virtual double fitness(Particle *part, int dimensions)=0;

    virtual double getInitialBest() const = 0;

protected:
    virtual bool isInSpace(double d)=0;
};

#endif // IALGORITHM_H
