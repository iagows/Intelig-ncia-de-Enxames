#ifndef VELOCITYINERTIADECREASE_H
#define VELOCITYINERTIADECREASE_H

#include "velocity/ivelocity.h"

class VelocityInertiaDecrease : public IVelocity
{
public:
    VelocityInertiaDecrease();
    ~VelocityInertiaDecrease() override;

    void calculate(Particle *particle, int pos, double maxVel, int loopCount, int maxLoop) override;
};

#endif // VELOCITYINERTIADECREASE_H
