#include "ground.h"

#include "util/point.h"

Ground::Ground()
{

}

Ground::~Ground()
{
    for(auto& it : *this->cities)
    {
        for(auto& p : *it)
        {
            delete p;
        }
        delete it;
    }
    delete this->cities;
}

void Ground::createCities(std::vector<int> *vec)
{
    int size = vec->size()-1;
    this->cities = new std::vector<std::vector<Path*> *>();
    Point arr[vec->size()/2];
    for(int i=0; i<size; i+=2)
    {
        arr[i/2].x = vec->at(i);
        arr[i/2].y = vec->at(i+1);

        this->cities->push_back(new std::vector<Path*>);//adicionando colunas
    }
    size = vec->size()/2;
    for(int i=0; i<size; ++i)
    {
        //linha i
        Point from = arr[i];
        for(int j=0; j<size; ++j)
        {
            //coluna j
            Point to = arr[j];

            int distance =  Point::distance(from, to);

            Path *p = new Path();
            p->setDistance(distance);

            this->cities->at(i)->push_back(p);
        }
    }
}



Path *Ground::at(int i, int j)
{
    /*if(i>j)
    {
        int temp = j;
        j = i;
        i = temp;
    }*/

    return this->cities->at(i)->at(j);
}

int Ground::size()
{
    return this->cities->size();
}
