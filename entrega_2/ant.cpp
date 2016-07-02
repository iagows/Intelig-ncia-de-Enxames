#include "ant.h"

Ant::Ant()
{
    this->distance = 0;
}

Ant::~Ant()
{

}

void Ant::addCity(int c)
{
    this->visited.push_back(c);
}

const std::vector<int> Ant::getVisited()
{
    return this->visited;
}

void Ant::clearVisited()
{
    this->visited.clear();
    this->distance = 0;
}

void Ant::addDistance(int d)
{
    this->distance += d;
}

int Ant::getDistance()
{
    return this->distance;
}

bool Ant::hasVisited(int v)
{
    bool has = false;
    for(auto &val : this->visited)
    {
        if(v == val)
        {
            has = true;
            break;
        }
    }
    return has;
}

int Ant::getLast()
{
    return this->visited.at(visited.size()-1);
}

void Ant::popFirst()
{
    this->visited.erase(visited.begin());
}
