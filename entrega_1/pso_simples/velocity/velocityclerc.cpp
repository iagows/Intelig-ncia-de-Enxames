#include "velocityclerc.h"
#include <math.h>
VelocityClerc::VelocityClerc()
{
    this->ran = new IagoRandom();

    this->c1 = ran->randRange(1,4);
    c2 = 4.1 - c1;
    this->phi = getPhi();
    this->X = getX();
}

VelocityClerc::~VelocityClerc()
{
    delete this->ran;
}

void VelocityClerc::calculate(Particle *particle, int pos, double maxVel, int loopCount, int maxLoop)
{
    double rand1 = ran->randNormal();
    double rand2 = ran->randNormal();

    double velocity = X*(particle->getVelocity(pos) +
                                 (c1 * rand1 * (particle->getPBest(pos) - particle->getData(pos))) +
                                 (c2 * rand2 * (particle->getGBest()->at(pos) - particle->getData(pos))));

    particle->setVelocity(pos, velocity);
}

double VelocityClerc::getX()
{
    double root = sqrt((phi*phi)-(4*phi));
    double bot = 2 - phi - root;
    if(bot < 0) bot = -bot;
    return 2/bot;
}

double VelocityClerc::getPhi()
{
    return c1+c2;
}
