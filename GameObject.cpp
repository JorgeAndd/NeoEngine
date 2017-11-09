#include "GameObject.h"

GameObject::GameObject(float Posx, float Posy, float width, float height)
{
    box.x = Posx;
    box.y = Posy;
    box.w = width;
    box.h = height;
    hitBall = height/2;
}

Rect GameObject::getBox()
{
    return box;
}

float GameObject::getHitBall()
{
    return hitBall;
}

void GameObject::setHitBall(float ball_radio)
{
    hitBall = ball_radio;
}

void GameObject::changeHitBall(float ratio)
{
    hitBall *= ratio;
}

bool GameObject::collidesWith(GameObject *other)
{
    float radios,dx,dy,distance;

    radios = hitBall + other->getHitBall();
    dx = (box.x - other->getBox().x);
    dy = (box.y - other->getBox().y);
    distance = sqrt((dx*dx)+(dy*dy));

    if(distance <= radios) return true;
    else return false;
}
