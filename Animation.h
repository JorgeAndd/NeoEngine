#pragma once

#include "Sprite.h"

class Animation : public Sprite
{
    private:
        float time;
        float frameTime;
        int n_sprites;
    public:
        Animation(std::string path, float duration, int n_sprites); //Construtor

        void update();                  //Atualiza o frame atual da anima��o
        void render(int x, int y);      //Renderiza a anima��o na posi��o x,y

        void setFrame(int frame);       //Define o frame atual da anima��o
        void setDuration(float time);   //Define a dura��o total da anima��o


        //---------------Fun��es de retorno------------

        float getDuration();    //Retorna a dura��o total da anima��o
        int getFrame();         //Retorna o frame atual da anima��o
};
