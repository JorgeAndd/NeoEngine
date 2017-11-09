#pragma once

#include "GameObject.h"
#include "Sprite.h"
#include "Point.h"

class Planet : public GameObject
{
    protected:
        Sprite *sprite;
    public:
        Planet(Sprite *sprite, float x, float y);

        void render(float cameraX = 0.0, float cameraY = 0.0);

        Sprite* getSprite();
        Point getPos();

        void changePosX(float dx);
        void changePosY(float dy);

        void update();
};
