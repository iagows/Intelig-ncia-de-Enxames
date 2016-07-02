#ifndef PATH_H
#define PATH_H


class Path
{
public:
    Path();

    void setDistance(int d);
    int getDistance();
    void setPheromone(double p);
    double getPheromone();

    double getInfluence(double alpha, double beta);

private:
    int distance;//inicializada com o pior caso que um INT aguenta
    double pheromone;//inicialido com 0
};

#endif // PATH_H
