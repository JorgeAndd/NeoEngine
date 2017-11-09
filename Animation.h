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

        void update();                  //Atualiza o frame atual da animação
        void render(int x, int y);      //Renderiza a animação na posição x,y

        void setFrame(int frame);       //Define o frame atual da animação
        void setDuration(float time);   //Define a duração total da animação


        //---------------Funções de retorno------------

        float getDuration();    //Retorna a duração total da animação
        int getFrame();         //Retorna o frame atual da animação
};
