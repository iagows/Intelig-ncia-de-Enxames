#include "velocityinertia.h"

VelocityInertia::VelocityInertia()
{
    this->ran = new IagoRandom();
}

VelocityInertia::~VelocityInertia()
{
    delete this->ran;
}

void VelocityInertia::calculate(Particle *particle, int pos, double maxVel, int loopCount, int maxLoop)
{
    double w = 0.8;
    double c1 = 2.05;
    double c2 = 2.05;

    double rand1 = ran->randNormal();
    double rand2 = ran->randNormal();

    double p1 = w* (particle->getVelocity(pos));
    double p2 = c1 * rand1 * (particle->getPBest(pos) - particle->getData(pos));
    double p3 = c2 * rand2 * (particle->getGBest()->at(pos) - particle->getData(pos));
    double velocity = p1 + p2 + p3;

    //clamping
    if(velocity > maxVel)
        velocity = maxVel;

    if(velocity < -maxVel)
        velocity = -maxVel;

    particle->setVelocity(pos, velocity);
}
