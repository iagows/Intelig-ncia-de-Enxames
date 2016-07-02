#ifndef IALGORITHM_H
#define IALGORITHM_H

#include "fish.h"

class IAlgorithm
{
public:
    IAlgorithm() { }
    virtual ~IAlgorithm() { }

    virtual void init(double &min, double &max)=0;
    virtual double fitness(std::vector<double>* data)=0;

    virtual double getInitialBest() const = 0;

protected:
    virtual bool isInSpace(double d)=0;
};

#endif // IALGORITHM_H
