#ifndef VELOCITYNORMAL_H
#define VELOCITYNORMAL_H

#include "velocity/ivelocity.h"

#include "iagorandom.h"

class VelocityNormal : public IVelocity
{
public:
    VelocityNormal();
    ~VelocityNormal() override;

    void calculate(Particle *particle, int pos, double maxVel, int loopCount, int maxLoop) override;
};

#endif // VELOCITYNORMAL_H
