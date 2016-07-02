#include "topologyring.h"

TopologyRing::TopologyRing():AbstractTopology()
{
    this->localBests = nullptr;
    this->lBest = nullptr;
}

TopologyRing::~TopologyRing()
{

}

void TopologyRing::init(int size)
{
    AbstractTopology::init(size);
    this->localBests = new std::vector<double>(size);
    this->lBest = new std::vector<Particle*>(size);
    std::fill(localBests->begin(), localBests->end(), INT32_MAX);//pior caso
}

void TopologyRing::setBest(int pos, std::vector<Particle *> *vec)
{
    Particle *current = vec->at(pos);
    Particle *b = this->lBest->at(pos);
    if(b!=nullptr)
        current->setGBest(b->getData());
}

void TopologyRing::updateBest(std::vector<Particle *> *vec)
{
    for(int i=0, size=vec->size(); i<size; ++i)
    {
        double fit = this->allFits->at(i);
        double localBest = this->localBests->at(i);

        int lastIndex = i == 0 ? vec->size()-1 : i-1;
        int nextIndex = i == (vec->size()-1) ? 0 : i+1;
        double lastBest = this->localBests->at(lastIndex);
        double nextBest = this->localBests->at(nextIndex);

        if((fit < lastBest) && (fit<nextBest))
        {
            if(fit<=localBest)
            {
                this->localBests->at(i) = fit;
                this->lBest->at(i) = vec->at(i);
            }
        }
        else if(lastBest < nextBest)
        {
            if(lastBest<=localBest)
            {
                this->localBests->at(i) = lastBest;
                this->lBest->at(i) = vec->at(lastIndex);
            }
        }
        else
        {
            if(nextBest <= localBest)
            {
                this->localBests->at(i) = nextBest;
                this->lBest->at(i) = vec->at(nextIndex);
            }
        }
    }
}

double TopologyRing::getBest()
{
    double out = INT32_MAX;
    for(int i=0, size=this->localBests->size(); i<size; ++i)
    {
        double current = localBests->at(i);
        if(current<out)
            out=current;
    }
    return out;

    //pBest
    /*double out = INT32_MAX;
    int bestIndex = 0;
    for(int i=0, size=this->localBests->size(); i<size; ++i)
    {
        double current = localBests->at(i);
        if(current<out)
        {
            out=current;
            bestIndex=i;
        }
    }
    out = 0;
    Particle *b = this->lBest->at(bestIndex);
    int size = b->getPBest()->size();
    for(int i=0; i<size; ++i)
    {
        out += b->getPBest()->at(i);
    }
    out /= size;
    return out;*/
}
