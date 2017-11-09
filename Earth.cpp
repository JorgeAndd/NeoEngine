#include "Earth.h"

Earth::Earth(Sprite *sprite, float x, float y, int hp) : Planet(sprite,x,y,hp)
{
    speedX = 0;
    speedY = 0;
}
