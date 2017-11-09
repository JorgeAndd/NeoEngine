#pragma once

#include "SDLBase.h"
#include "Rect.h"

class GameObject
{
    protected:
        Rect box;
        float hitBall;  //hitBall ratio
    public:
        GameObject(float x, float y, float w = 0, float h = 0);
        virtual void update() = 0;
        virtual void render(float cameraX, float cameraY) = 0;

        Rect getBox();
        float getHitBall();

        void setHitBall(float ball_radio);
        void changeHitBall(float ratio);
        bool collidesWith(GameObject *other); //Checa colisão esfera-esfera
};
