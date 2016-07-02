#ifndef SWARM_H
#define SWARM_H

#include "algorithms/algorithmfactory.h"
#include "topology/topologyfactory.h"
#include "velocity/velocityfactory.h"

#include "iagorandom.h"

class Swarm
{
public:
    Swarm(int partAmount, int dimAmount, int maxEpoch,
          TopologyFactory::TOPOLOGY top, AlgorithmFactory::ALGORITHM algorithm,
          VelocityFactory::TYPE velType);
    ~Swarm();

    std::vector<double> *psoAlg();

private:
    int particleAmount;
    int dimensionAmount;
    double maxVelocity;
    int maxEpoch;

    double rangeMin;
    double rangeMax;

    std::vector<Particle*> *particles;

    int epoch;
    bool done;

    IAlgorithm *algorithm;

    ITopology *topology;
    IVelocity *velocity;

    void initialize();

    void calculateVelocity(Particle* part, int pos);
    void calculateVelocityW(Particle* part, int pos);
    void calculateVelocityDec(Particle* part, int pos);
    void initClerc();
    double _c1;
    double _c2;
    double _phi;
    double _X;
    void calculateVelocityC(Particle* part, int pos);
    void updatePosition(Particle* part, int pos);

    void randomSpeed(Particle* part);

    double sumVector(std::vector<double> *v);

    IagoRandom *ran;
};

#endif // SWARM_H
