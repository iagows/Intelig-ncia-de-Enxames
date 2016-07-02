#include "abstracttestalgorithm.h"

AbstractTestAlgorithm::AbstractTestAlgorithm()
{

}

AbstractTestAlgorithm::~AbstractTestAlgorithm()
{

}

bool AbstractTestAlgorithm::isInSpace(double d)
{
    return (d > -this->max) && (d < this->max);
}
