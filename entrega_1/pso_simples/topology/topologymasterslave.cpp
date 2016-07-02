#include "topologymasterslave.h"

TopologyMasterSlave::TopologyMasterSlave()
    :AbstractTopology()
{
    this->focal = nullptr;
    this->localBests = nullptr;
}

TopologyMasterSlave::~TopologyMasterSlave()
{

}

void TopologyMasterSlave::init(int size)
{
    AbstractTopology::init(size);
    this->localBests = new std::vector<double>(size);
    std::fill(localBests->begin(), localBests->end(), INT32_MAX);//pior caso
}

void TopologyMasterSlave::setBest(int pos, std::vector<Particle *> *vec)
{
    //if(pos==0) return;
    Particle *current = vec->at(pos);
    Particle *b = this->focal;
    if(b!=nullptr)
        current->setGBest(b->getData());
}

void TopologyMasterSlave::updateBest(std::vector<Particle *> *vec)
{
    this->focal = vec->at(0);
    for(int i=0, size=vec->size(); i<size; ++i)
    {
        double fit = this->allFits->at(i);
        if(i==0)
        {
            for(int j=1; j<size; ++j)
            {
                Particle *slave = vec->at(j);
                if(slave->getFitness() <= focal->getFitness())
                {
                    focal->setFitness(slave->getFitness());
                    focal->setGBest(slave->getData());
                }
                if(fit <= focal->getFitness())
                {
                    focal->setFitness(fit);
                    focal->setGBest(slave->getData());
                }
            }
        }
        else
        {
            Particle *slave = vec->at(i);
            if(fit <= focal->getFitness())
            {
                focal->setFitness(fit);
                focal->setGBest(slave->getData());
            }
        }
    }
}

double TopologyMasterSlave::getBest()
{
    return focal->getFitness();
    //gbests
    /*double out = 0;
    int size = this->focal->getPBest()->size();
    for(int i=0; i<size; ++i)
    {
        out += focal->getPBest()->at(i);
    }
    out /= size;
    return out;*/
}
