#pragma once

#include <queue>
#include "GameObject.h"
#include "Point.h"
#include "Sprite.h"
#include <math.h>

class FollowerObject : public GameObject
{
    private:
        double fps;
        Sprite *sprite;
        float speedX, speedY;
        std::queue<Point> movQueue;
    public:
        FollowerObject(Sprite *sprite, float x, float y);
        void update();
        void render(float cameraX, float cameraY);
        void renderQueueLines(float cameraX, float cameraY);
        void enqueue(Point position);
};
