#ifndef ACO_H
#define ACO_H

#include "ground.h"
#include "ant.h"
#include <string>
class ACO
{
public:
    ACO(double alpha, double beta, int pheromoneQ, double pheromoneRho, std::string fileOpen, bool useOnlyQ, int pushNum);
    ~ACO();

    std::vector<int> run(int epoch);

    void createAnts(int amount);

    int walk();

    void antStep(Ant* ant);

private:
    Ground* ground;
    std::vector<Ant*> *ants;

    int pheromoneQ;
    int pushNum;
    double pheromoneRho;
    void resetAnts();
    void putPheromone();
    int lowestPath();

    double alpha;
    double beta;

    int roulette(std::vector<double> &vec);
    bool useQ;
};

#endif // ACO_H
