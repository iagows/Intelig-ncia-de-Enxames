#include "topologystar.h"

TopologyStar::TopologyStar():AbstractTopology()
{
    this->gBest = nullptr;
}

TopologyStar::~TopologyStar()
{

}

void TopologyStar::init(int size)
{
    AbstractTopology::init(size);
    this->globalBest = INT32_MAX;//pior caso possível
}

void TopologyStar::setBest(int pos, std::vector<Particle *> *vec)
{
    Particle *current = vec->at(pos);
    current->setGBest(gBest->getData());
}

void TopologyStar::updateBest(std::vector<Particle *> *vec)
{
    for(int i=0, size=vec->size(); i<size; ++i)
    {
        double fit = this->allFits->at(i);
        if(fit <= globalBest)
        {
            Particle* current = vec->at(i);
            globalBest = fit;
            this->gBest = current;
        }
    }
}

double TopologyStar::getBest()
{
    return this->globalBest;
    //pbest
    /*double out = 0;
    int size = gBest->getPBest()->size();
    for(int i=0; i<size; ++i)
    {
        out += gBest->getPBest()->at(i);
    }
    out /= size;
    return out;*/
}
