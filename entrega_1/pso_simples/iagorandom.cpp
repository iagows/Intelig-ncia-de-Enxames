#include "iagorandom.h"

#ifdef WINDOWS
    #include <time.h>
#endif

IagoRandom::IagoRandom()
{

}
double IagoRandom::randRange(double min, double max)
{
    srand(time(NULL));
    int output = (rand()%(int)(max-min+1))+min;
    return output;
}

double IagoRandom::randNormal()
{
    return (double)rand()/RAND_MAX;
}
