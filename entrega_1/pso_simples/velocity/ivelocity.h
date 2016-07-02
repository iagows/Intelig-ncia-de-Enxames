#ifndef IVELOCITY_H
#define IVELOCITY_H

#include "particle.h"

#include "iagorandom.h"
class IVelocity
{
public:
    IVelocity() { this->ran = nullptr; }
    virtual ~IVelocity() { }

    virtual void calculate(Particle *particle, int currentdimension, double maxVel, int loopCount, int maxLoop)=0;
    IagoRandom *getRandom() { return this->ran; }

protected:
    IagoRandom *ran;
};

#endif //IVELOCITY_H
