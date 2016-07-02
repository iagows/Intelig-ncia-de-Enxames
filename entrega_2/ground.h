#ifndef GROUND_H
#define GROUND_H

#include "path.h"
#include <vector>

class Ground
{
public:
    Ground();
    ~Ground();

    void createCities(std::vector<int> *vec);

    Path* at(int i, int j);

    int size();

private:
    std::vector<std::vector<Path*>*> *cities;
};

#endif // GROUND_H
