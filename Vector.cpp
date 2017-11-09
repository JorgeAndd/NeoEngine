#include <cmath>
#include "Vector.h"

float Vector::length() const
{
    return sqrt(x*x + y*y);
}

void Vector::normalize()
{
    float len = length();

    if (len > 0)
    {
        x /= len;
        y /= len;
    }
}

Vector Vector::normalize(const Vector &v)
{
    Vector result(v);
    result.normalize();
    return result;
}

Vector &Vector::operator+=(const Vector &vector)
{
    x += vector.x;
    y += vector.y;
    return *this;
}

Vector &Vector::operator-=(const Vector &vector)
{
    x -= vector.x;
    y -= vector.y;
    return *this;
}

Vector &Vector::operator*=(float value)
{
    x *= value;
    y *= value;
    return *this;
}

Vector &Vector::operator/=(float value)
{
    x /= value;
    y /= value;
    return *this;
}

Vector operator+(const Vector &a, const Vector &b)
{
    return Vector(a.x + b.x, a.y + b.y);
}

Vector operator-(const Vector &a, const Vector &b)
{
    return Vector(a.x - b.x, a.y - b.y);
}

Vector operator*(const Vector &a, float b)
{
    return Vector(a.x * b, a.y * b);
}

Vector operator/(const Vector &a, float b)
{
    return Vector(a.x / b, a.y / b);
}

Vector Vector::unit(float angle)
{
    return Vector(std::cos(angle), std::sin(angle));
}
