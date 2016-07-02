#ifndef TOPOLOGYRING_H
#define TOPOLOGYRING_H

#include "abstracttopology.h"

class TopologyRing : public AbstractTopology
{
public:
    TopologyRing();
    ~TopologyRing() override;

    void init(int size) override;
    void setBest(int pos, std::vector<Particle*> *vec) override;

    void updateBest(std::vector<Particle*> *vec) override;
    virtual double getBest() override;
private:
    std::vector<double> *localBests;
    std::vector<Particle*> *lBest;
};

#endif // TOPOLOGYRING_H
