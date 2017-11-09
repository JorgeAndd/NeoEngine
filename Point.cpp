#include "Point.h"

Point &Point::operator+=(const Point &point)
{
    x += point.x;
    y += point.y;
    return *this;
}

Point &Point::operator-=(const Point &point)
{
    x -= point.x;
    y -= point.y;
    return *this;
}
