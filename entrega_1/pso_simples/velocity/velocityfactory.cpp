#include "velocityfactory.h"

VelocityFactory::VelocityFactory(VelocityFactory::TYPE type)
{
    this->vel = nullptr;
    switch (type)
    {
    default:
    case TYPE::NORMAL:
        this->vel = new VelocityNormal();
        break;
    case TYPE::INERTIA:
        this->vel = new VelocityInertia();
        break;
    case TYPE::INERTIA_DECREASE:
        this->vel = new VelocityInertiaDecrease();
        break;
    case TYPE::CLERC:
        this->vel = new VelocityClerc();
        break;
    }
}

VelocityFactory::~VelocityFactory()
{

}

IVelocity *VelocityFactory::get()
{
    return this->vel;
}
