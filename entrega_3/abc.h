#ifndef ABC_H
#define ABC_H

#include "bee.h"
#include "algorithms/algorithmfactory.h"

class ABC
{
public:
    ABC(int colSize, int initBN, int initBE, int dim, int maxEpoch, AlgorithmFactory::ALGORITHM alg);
    ~ABC();
    void initialize();
    std::vector<double> *search();
    double getBestFitness();

private:
    int CS;//tamanho da colônia (colony size)
    int BN;//campeiras
    int FS;//fontes de alimento
    int BC;//seguidoras
    int BE;//escudeiras
    int lim;//limite para liberar fonte

    int dimensions;

    int maxEpoch;

    void createColony();
    void createFollowers();
    std::vector<Bee*>* colony;
    std::vector<Bee*>* followers;
    IAlgorithm* alg;

    double min, max;

    std::vector<Bee*>* finders;
    void createFoodSources();

    double getRandom(double min=0.0, double max=1.0);

    double bestFitness;
    void setBestFitness(double fit);

    void step();
    int roulette(std::vector<double> &vec);
};

#endif // ABC_H
