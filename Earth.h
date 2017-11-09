#pragma once

#include "Planet.h"

class Earth : public Planet
{
    private:
        float speedX, speedY;
    public:
        Earth(Sprite *sprite, float x, float y, int hp = 1); //Construtor
};
