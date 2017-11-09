#pragma once

#include "Sprite.h"
#include "Point.h"
#include "Vector.h"

class Compass
{
    private:
        Sprite *sprite;
        float angle, diff_x, diff_y;
    public:
        Compass(Sprite *sprite);    //Construtor
        void update(Point point1, Point point2);    //Atualiza o �ngulo da b�ssola
        void render(float x, float y);  //Renderiza a b�ssola na posi��o x,y
};
