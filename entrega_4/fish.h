#ifndef FISH_H
#define FISH_H

#include <vector>

class Fish
{
public:
    Fish(int size);
    ~Fish();
    void setData(int i, double val);
    double getData(int i);
    std::vector<double>* getData();
    void setData(std::vector<double> *v);
    std::vector<double>* cloneData();
    double getFitness();
    void setFitness(double val);

    double getWeight();
    void setWeight(double d);

    std::vector<double> *getDeltaX();
    double getDeltaF();

    void resetDelta();
private:
    std::vector<double>* data;//posição N-dimensional
    double fitness;
    double weight;

    double maxW;

    double deltaF;
    std::vector<double>* deltaX;
};

#endif // FISH_H
