#pragma once

#include <Math.h>

class Vector
{
    public:
        float x, y;

        Vector(float x = 0, float y = 0) : x(x), y(y){}

        float length() const;
        void normalize();

        static Vector normalize(const Vector &vector);
        static Vector unit(float angle);


        Vector &operator+=(const Vector &vector);
        Vector &operator*=(float value);
        Vector &operator/=(float value);
        Vector &operator-=(const Vector &vector);
};

Vector operator+(const Vector &a, const Vector &b);
Vector operator-(const Vector &a, const Vector &b);
Vector operator*(const Vector &a, float b);
Vector operator/(const Vector &a, float b);

