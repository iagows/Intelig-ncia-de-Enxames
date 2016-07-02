#include "point.h"

#include <cmath>

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}


double Point::distance(Point &p1, Point &p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(pow(dx,2) + pow(dy,2));
}
