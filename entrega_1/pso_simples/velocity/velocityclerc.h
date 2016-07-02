#ifndef VELOCITYCLERC_H
#define VELOCITYCLERC_H

#include "velocity/ivelocity.h"

class VelocityClerc : public IVelocity
{
public:
    VelocityClerc();
    ~VelocityClerc() override;

    void calculate(Particle *particle, int pos, double maxVel, int loopCount, int maxLoop) override;

private:
    double getX();
    double getPhi();

    double c1;
    double c2;
    double X;
    double phi;
};

#endif // VELOCITYCLERC_H
