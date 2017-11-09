#pragma once

#include "Timer.h"
#include "GameObject.h"
#include "Animation.h"
#include "Point.h"
#include "Vector.h"


class AccObject : public GameObject
{
    protected:
        Animation *animation;
        Vector velocity;
        int hp;
        float rotation, maxSpeed, acceleration;
        bool accelerating;
        float angularSpeed;
    public:
        AccObject(Animation *animation, float x, float y, int hp, float maxSpeed);  //Construtor
        void render(float cameraX, float cameraY);      //Destrutor
        void update();  //Atualiza a velocidade e posição da nave

        void changeHp(int hp_change); //Incrementa o hp da nave por hp_change
        void setHp(int new_hp); //Define o hp da nave como new_hp

        void setAngularSpeed(float value);  //Define a angularSpeed da nave como value
        void accelerate();  //Define acceleration como true


        //---------------Funções de retorno------------

        int getHp();        //Retorna o hp da nave
        Point getPos();     //Retorna a posição da nave(x,y)
};
