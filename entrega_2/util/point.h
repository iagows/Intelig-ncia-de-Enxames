#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point();
    Point(int x, int y);

    static double distance(Point &p1, Point &p2);

    int x;
    int y;
};

#endif // POINT_H
