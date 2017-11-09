#include "Planet.h"

Planet::Planet(Sprite *sprite, float x, float y) : GameObject(x, y, sprite->getWidth(), sprite->getHeight()), sprite(sprite)
{
}

void Planet::render(float cameraX, float cameraY)
{
    if(sprite)
        sprite->render(box.x - cameraX, box.y - cameraY);
}

Sprite* Planet::getSprite()
{
    return sprite;
}

Point Planet::getPos()
{
    Point position;

    position.x = box.x;
    position.y = box.y;

    return position;
}

void Planet::changePosX(float dx)
{
    box.x += dx;
}

void Planet::changePosY(float dy)
{
    box.y += dy;
}

void Planet::update(){

}
