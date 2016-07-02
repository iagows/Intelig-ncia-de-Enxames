#include "velocitynormal.h"

VelocityNormal::VelocityNormal()
{
    this->ran = new IagoRandom();
}

VelocityNormal::~VelocityNormal()
{
    delete this->ran;
}

void VelocityNormal::calculate(Particle *particle, int pos, double maxVel, int loopCount, int maxLoop)
{
    (void)loopCount;
    (void)maxLoop;

    double c1 = 2.05;
    double c2 = 2.05;

    double rand1 = ran->randNormal();
    double rand2 = ran->randNormal();

    double velocity = (particle->getVelocity(pos) +
                                 (c1 * rand1 * (particle->getPBest(pos) - particle->getData(pos))) +
                                 (c2 * rand2 * (particle->getGBest()->at(pos) - particle->getData(pos))));

    //clamping
    if(velocity > maxVel)
        velocity = maxVel;

    if(velocity < -maxVel)
        velocity = -maxVel;

    particle->setVelocity(pos, velocity);
}
