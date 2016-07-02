#ifndef VELOCITYFACTORY_H
#define VELOCITYFACTORY_H

#include "velocity/velocitynormal.h"
#include "velocity/velocityinertia.h"
#include "velocity/velocityinertiadecrease.h"
#include "velocity/velocityclerc.h"

class VelocityFactory
{
public:
    enum TYPE
    {
        NORMAL,
        INERTIA,
        INERTIA_DECREASE,
        CLERC
    };

    VelocityFactory(TYPE type);
    ~VelocityFactory();

    IVelocity *get();

private:
    IVelocity *vel;

};

#endif // VELOCITYFACTORY_H
