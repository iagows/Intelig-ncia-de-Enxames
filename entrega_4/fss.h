#ifndef FSS_H
#define FSS_H

#include "fish.h"

#include "algorithms/algorithmfactory.h"

class FSS
{
public:
    FSS(int fishAmount, int dim, int epoch, AlgorithmFactory::ALGORITHM alg);
    ~FSS();

    std::vector<double> *work();
private:
    std::vector<Fish*>* fishes;

    int dimensions;

    void step();
    void initializeFish(int size);
    void individualMovement(Fish* f);
    void getMaxDelta(double &maxF);
    void feeding(Fish *f, double maxDeltaF);

    void instinctiveMovement(Fish *f, std::vector<double> v);
    std::vector<double> *barycentre(double &total);
    void volitiveMovement(Fish *f, bool increased, std::vector<double> *b);
    void updateStep();

    double getRandom(double min=0.0, double max=1.0);
    double euclideanDistance(std::vector<double> *a, std::vector<double> *b);

    IAlgorithm* alg;
    double min;
    double max;
    int epoch;

    double stepSize;
    double lastW;

    double bestFit;
};

#endif // FSS_H
