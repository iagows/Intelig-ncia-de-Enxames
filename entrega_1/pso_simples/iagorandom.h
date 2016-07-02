#ifndef IAGORANDOM_H
#define IAGORANDOM_H

#include <random>

class IagoRandom
{
public:
    IagoRandom();

    double randRange(double min, double max);
    double randNormal();

private:

};

#endif // IAGORANDOM_H
