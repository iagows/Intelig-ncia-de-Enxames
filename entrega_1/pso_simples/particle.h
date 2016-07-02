#ifndef PARTICLE_H
#define PARTICLE_H

#include <vector>
#include <string>
#include <iostream>

class Particle
{
public:
    Particle(int dataSize, int defaultValue=0);
    ~Particle();

    double getData(double pos) const;
    std::vector<double> *getData() const;
    void setData(int pos, double value);

    void setPBest(std::vector<double> *pb);
    double getPBest(int pos);
    std::vector<double> *getPBest();

    void setGBest(std::vector<double> *gb);
    std::vector<double> *getGBest() const;

    double getVelocity(int pos) const;
    void setVelocity(int pos, double value);

    double getFitness() const;
    void setFitness(double val);

private:
    std::vector<double>* data;
    std::vector<double>* pBest;
    std::vector<double>* velocity;
    std::vector<double>* gBest;

    double fitness;
};

#endif // PARTICLE_H
