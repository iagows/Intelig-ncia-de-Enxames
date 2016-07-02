#ifndef PSO_SIMPLES_H
#define PSO_SIMPLES_H

#include "pso_simples_global.h"

#include "swarm.h"

class PSO_SIMPLESSHARED_EXPORT Pso_simples
{
public:
    Pso_simples();
    ~Pso_simples();

    std::vector<double>* getMean(double &time, int runs=30, int particles=30, int dimensions=30, int epoch = 10000,
                                 TopologyFactory::TOPOLOGY top = TopologyFactory::TOPOLOGY::STAR,
                                 AlgorithmFactory::ALGORITHM alg = AlgorithmFactory::ALGORITHM::SPHERE,
                                 VelocityFactory::TYPE vel = VelocityFactory::TYPE::INERTIA);
};

#endif // PSO_SIMPLES_H
