#include "abstracttopology.h"

AbstractTopology::AbstractTopology()
{

}

AbstractTopology::~AbstractTopology()
{
    delete this->allFits;
}

void AbstractTopology::init(int size)
{
    this->allFits = new std::vector<double>(size);
}

void AbstractTopology::addFit(int pos, double fit)
{
    this->allFits->at(pos) = fit;
}
