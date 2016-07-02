#ifndef TOPOLOGYMASTERSLAVE_H
#define TOPOLOGYMASTERSLAVE_H

#include "topology/abstracttopology.h"

class TopologyMasterSlave : public AbstractTopology
{
public:
    TopologyMasterSlave();
    ~TopologyMasterSlave() override;

    void init(int size) override;
    void setBest(int pos, std::vector<Particle*> *vec) override;

    void updateBest(std::vector<Particle*> *vec) override;
    virtual double getBest() override;
private:
    std::vector<double> *localBests;
    Particle *focal;
};

#endif // TOPOLOGYMASTERSLAVE_H
