#pragma once

class Point
{
    public:
        float x,y;

        Point(float x = 0, float y = 0) : x(x), y(y){}

        Point &operator+=(const Point &point);
        Point &operator-=(const Point &point);
};
