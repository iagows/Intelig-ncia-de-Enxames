#include "topologyfactory.h"

TopologyFactory::TopologyFactory(TopologyFactory::TOPOLOGY top)
{
    switch (top) {
    default:
    case TOPOLOGY::STAR:
        this->topology = new TopologyStar();
        break;
    case TOPOLOGY::MASTER_SLAVE:
        this->topology = new TopologyMasterSlave();
        break;
    case TOPOLOGY::RING:
        this->topology = new TopologyRing();
        break;
    }
}

TopologyFactory::~TopologyFactory()
{

}

ITopology *TopologyFactory::get()
{
    return this->topology;
}
