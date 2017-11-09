#include "FollowerObject.h"

#define MaxSpeed 800.f

FollowerObject::FollowerObject(Sprite *sprite, float x, float y) : GameObject(x, y, sprite->getWidth(), sprite->getHeight()),sprite(sprite)
{
}

void FollowerObject::update()
{
    Point delta;
    float modulo;

    if (!movQueue.empty())
    {

        delta.x = movQueue.front().x - box.x;
        delta.y = movQueue.front().y - box.y;

        modulo = sqrt(delta.x * delta.x + delta.y * delta.y);

        if (modulo > MaxSpeed * TIME_STEP)
        {
            delta.x *= (MaxSpeed * TIME_STEP)/modulo;
            delta.y *= (MaxSpeed * TIME_STEP)/modulo;
        }else
            movQueue.pop();

        box.x += delta.x;
        box.y += delta.y;
    }
}

void FollowerObject::render(float cameraX, float cameraY)
{
    sprite->render(box.x - cameraX, box.y - cameraY);
}

void FollowerObject::renderQueueLines(float cameraX, float cameraY)
{
    std::queue<Point> Qaux;
    Point last1, last2;

    last1.x = box.x;
    last1.y = box.y;

    while(!movQueue.empty())
    {
        last2 = movQueue.front();
        SDLBase::drawLine(last2.x-cameraX,last2.y-cameraY,last1.x-cameraX,last1.y-cameraY,0xFFFFFFFF,5);
        movQueue.pop();
        Qaux.push(last2);
        last1 = last2;
    }
    while(!Qaux.empty())
    {
        movQueue.push(Qaux.front());
        Qaux.pop();
    }
}

void FollowerObject::enqueue(Point position)
{
    Point pos;

    pos.x = position.x;
    pos.y = position.y;
    movQueue.push(pos);
}
