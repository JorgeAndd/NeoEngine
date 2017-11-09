#include "AccObject.h"

AccObject::AccObject(Animation *animation, float x, float y, int hp, float maxSpd) : GameObject(x,y,animation->getWidth(), animation->getHeight()),
                                                                                                animation(animation), hp(hp), maxSpeed(maxSpd)
{
    accelerating = false;
    angularSpeed = 0;
    rotation = 0;
}

void AccObject::render(float cameraX, float cameraY)
{
    animation->render(box.x-cameraX, box.y-cameraY);
}

void AccObject::update()
{
    rotation += angularSpeed * TIME_STEP;
    velocity *= 0.99f;

    if (accelerating)
    {
        velocity += Vector::unit(rotation) * maxSpeed * TIME_STEP;

        if (velocity.length() > maxSpeed)
        {
            velocity.normalize();
            velocity *= maxSpeed;
        }
    }

    accelerating = false;

    box.x += velocity.x * TIME_STEP;
    box.y += velocity.y * TIME_STEP;

    animation->rotoZoom(rotation + PI / 2.f,1,1,true);
    animation->update();
}

void AccObject::changeHp(int hp_change)
{
    hp += hp_change;
}

void AccObject::setHp(int hp_set)
{
    hp = hp_set;
}

void AccObject::setAngularSpeed(float speed)
{
    angularSpeed = speed;
}

void AccObject::accelerate()
{
    accelerating = true;
}

int AccObject::getHp()
{
    return hp;
}

Point AccObject::getPos()
{
    Point position;

    position.x = box.x;
    position.y = box.y;

    return position;
}
