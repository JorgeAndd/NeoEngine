#pragma once

#include "SDLBase.h"

class Sprite
{
    protected:
        SDL_Surface *surface;
        SDL_Surface *surfaceRotoZoom;
        SDL_Rect clipRect;
        float angle, scaleX, scaleY;
    public:
        Sprite(std::string path);       //Construtor
        virtual ~Sprite();                      //Destrutor

        void load(std::string path);     //Carrega uma imagem para a surface
        void clip(int x, int y, int w, int h);  //Clipa a surface na posição (x,y) e dimensões w e h da imagem


        void render(int x, int y); //Renderiza o sprite na tela na posição (x,y)

        void rotoZoom(float rotation, float zoomX = 1.0f, float zoomY = 1.0f, bool force = false); //Rotaciona e aplica zoom na sprite original
        void restore();     //Apaga a surface modificada


        //---------------Funções de retorno------------

        virtual int getWidth();     //Retorna a largura do sprite
        int getHeight();            //Retorna a altura do sprite
        SDL_Rect getClip();         //Retorna o retângulo de clip da imagem
        SDL_Surface* getSurface();  //Retorna a surface original do sprite
        SDL_Surface* getRotoZoom(); //Retorna a surface modificada do sprite
        float getScaleX();          //Retorna a escala X da surface modificada
        float getScaleY();          //Retorna a escala Y da surface modificada
};
