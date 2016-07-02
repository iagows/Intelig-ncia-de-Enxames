#ifndef ITOPOLOGY_H
#define ITOPOLOGY_H

#include <vector>
#include "particle.h"
class ITopology
{
public:
    ITopology() { }
    virtual ~ITopology() { }

    virtual void init(int size)=0;
    virtual void setBest(int pos, std::vector<Particle*> *vec)=0;

    virtual void addFit(int pos, double fit)=0;
    virtual void updateBest(std::vector<Particle*> *vec)=0;
    virtual double getBest()=0;
};

#endif // ITOPOLOGY_H
