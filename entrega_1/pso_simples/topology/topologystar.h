#ifndef TOPOLOGYSTAR_H
#define TOPOLOGYSTAR_H

#include "abstracttopology.h"

class TopologyStar : public AbstractTopology
{
public:
    TopologyStar();
    ~TopologyStar() override;

    void init(int size) override;
    void setBest(int pos, std::vector<Particle*> *vec) override;

    void updateBest(std::vector<Particle*> *vec) override;
    virtual double getBest() override;

private:
    double globalBest;
    Particle* gBest;
};

#endif // TOPOLOGYSTAR_H
