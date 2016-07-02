#ifndef VELOCITYINERTIA_H
#define VELOCITYINERTIA_H

#include "velocity/ivelocity.h"

class VelocityInertia : public IVelocity
{
public:
    VelocityInertia();
    ~VelocityInertia() override;

    void calculate(Particle *part, int pos, double maxVel, int loopCount, int maxLoop) override;
};

#endif // VELOCITYINERTIA_H
