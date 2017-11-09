#pragma once

#include <stdio.h>
#include <iostream>
#include <math.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_rotozoom.h>

#include "definitions.h"

class SDLBase
{
    private:
        static SDL_Surface *screen;
    public:
        static bool initSDL();  //Inicializa a SDL
        static void exitSDL();

        static SDL_Surface* loadImage(std::string path);    //Carrega uma imagem
        static void renderSurface(SDL_Surface *surface, SDL_Rect *clip = NULL, SDL_Rect *dst = NULL);   //Renderiza uma surface a partir do seu centro
        static void updateScreen();     //Atualiza a tela(screen)
        static void drawLine(int x1, int y1, int x2, int y2, int rgb, int spacing); //Desenha uma linha
        static SDL_Surface* rotoZoom(SDL_Surface *surface, float angle, float scalex = 1.0f, float scaley = 1.0f); //Rotaciona e redimensiona uma surface

        static SDL_Surface* getScreen();   //Retorna a tela(screen)
        static SDL_Surface* clip(SDL_Surface *original, SDL_Rect *clip);    //Retorna o clip de uma surface
};
