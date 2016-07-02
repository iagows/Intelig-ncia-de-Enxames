#ifndef TOPOLOGYFACTORY_H
#define TOPOLOGYFACTORY_H

#include "topology/topologystar.h"
#include "topology/topologyring.h"
#include "topology/topologymasterslave.h"

class TopologyFactory
{
public:
    enum TOPOLOGY
    {
        STAR,
        RING,
        MASTER_SLAVE
    };
    TopologyFactory(TOPOLOGY top);
    ~TopologyFactory();
    ITopology *get();

private:
    ITopology* topology;
};

#endif // TOPOLOGYFACTORY_H
