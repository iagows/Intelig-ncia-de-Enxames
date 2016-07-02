#ifndef ANT_H
#define ANT_H

#include <vector>

class Ant
{
public:
    Ant();
    ~Ant();

    void addCity(int c);
    const std::vector<int> getVisited();
    void clearVisited();

    void addDistance(const int d);
    int getDistance();

    bool hasVisited(int v);
    int getLast();
    void popFirst();

private:
    std::vector<int> visited;
    int distance;
};

#endif // ANT_H
