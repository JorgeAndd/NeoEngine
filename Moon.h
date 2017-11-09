#pragma once

#include "Planet.h"
#include <Math.h>

class Moon : public Planet
{
    private:
        float moonRadius, centerRadius, angle;
        Planet *center;
    public:
        Moon(Sprite *sprite, Planet *center);
        void update();
};
