#ifndef ABSTRACTTOPOLOGY_H
#define ABSTRACTTOPOLOGY_H

/** Classe que seleciona o tipo de algoritmo
 * de topologia a ser usado
 **/
#include "itopology.h"

class AbstractTopology : public ITopology
{
public:
    AbstractTopology();
    virtual ~AbstractTopology() override;

    virtual void init(int size);
    virtual void setBest(int pos, std::vector<Particle*> *vec)=0;

    virtual void addFit(int pos, double fit) override;
    virtual void updateBest(std::vector<Particle*> *vec)=0;
    virtual double getBest()=0;

protected:
    std::vector<double> *allFits;
};

#endif // ABSTRACTTOPOLOGY_H
