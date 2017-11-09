#include "Moon.h"
#include "Vector.h"

Moon::Moon(Sprite *sprite, Planet *center) : Planet(sprite, center->getBox().x, center->getBox().y), center(center)
{
    moonRadius = sprite->getClip().h/2;
    centerRadius = center->getSprite()->getClip().h/2;
    angle = 0;
}

void Moon::update()
{
    float dx, dy;

    angle += PI*TIME_STEP;

    dx = sin(angle)*(centerRadius);
    dy = cos(angle)*(centerRadius);

    box.x = center->getBox().x + center->getSprite()->getScaleX()*dx; //Multiplicando o dx por uma constante aumenta-se o "raio" em x
    box.y = center->getBox().y + center->getSprite()->getScaleY()*dy; //Multiplicando o dy por uma constante aumenta-se o "raio" em y
}
