#ifndef BEE_H
#define BEE_H

#include <vector>

class Bee
{
public:
    Bee(int size);
    ~Bee();
    void setData(int i, double val);
    double getData(int i);
    std::vector<double>* cloneData();
    double getFitness();
    void setFitness(double val);
    int trial;
private:
    std::vector<double>* data;//posição N-dimensional
    double fitness;
};

#endif // BEE_H
