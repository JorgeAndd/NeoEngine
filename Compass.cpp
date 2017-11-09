#include "Compass.h"

Compass::Compass(Sprite *sprite) : sprite(sprite)
{
    angle = 0;
}

void Compass::update(Point point1, Point point2)
{
    diff_x = point1.x - point2.x;
    diff_y = point1.y - point2.y;

    angle = atan2(diff_y, diff_x);

    sprite->rotoZoom(angle);
}

void Compass::render(float x, float y)
{
    sprite->render(x, y);
}
