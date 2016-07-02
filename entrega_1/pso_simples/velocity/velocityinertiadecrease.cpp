#include "velocityinertiadecrease.h"

VelocityInertiaDecrease::VelocityInertiaDecrease()
{
    this->ran = new IagoRandom();
}

VelocityInertiaDecrease::~VelocityInertiaDecrease()
{
    delete this->ran;
}

void VelocityInertiaDecrease::calculate(Particle *particle, int pos, double maxVel, int loopCount, int maxLoop)
{
    //w inicial
    double w = 0.9;
    //w final
    double endW = 0.4;

    //tamanho da reduçao por iteraçao
    double wStep = endW/maxLoop;

    //w atual apos reduçao por iteraçoes
    double currentW = w - (loopCount*wStep);

    double c1 = 2.05;
    double c2 = 2.05;

    double rand1 = ran->randNormal();
    double rand2 = ran->randNormal();

    double velocity = currentW*particle->getVelocity(pos) +(
                                 (c1 * rand1 * (particle->getPBest(pos) - particle->getData(pos))) +
                                 (c2 * rand2 * (particle->getGBest()->at(pos) - particle->getData(pos)))
                );

    //clamping
    if(velocity > maxVel)
        velocity = maxVel;

    if(velocity < -maxVel)
        velocity = -maxVel;

    particle->setVelocity(pos, velocity);
}
