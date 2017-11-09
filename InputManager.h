#pragma once

#include "SDLBase.h"
#include "GameObject.h"
#include "Point.h"

#define N_KEYS SDLK_LAST
#define N_MOUSE_BUTTONS 5

//Singleton para recebimento de input

class InputManager
{
    private:
        SDL_Event *event;
        bool keyState[N_KEYS], keyChanged[N_KEYS];
        bool mouseState[N_MOUSE_BUTTONS], mouseChanged[N_MOUSE_BUTTONS];
        float mouseX, mouseY;
        bool quit;
        static InputManager *instance;

    public:
        InputManager(); //Construtor
        static InputManager* getInstance(); //Retorna a inst�ncia do Singleton
        void update();  //Atualiza o input

        bool isKeyDown(int key);    //Verifica se uma tecla foi pressionada
        bool isKeyUp(int key);      //Verifica se uma tecla est� solta
        bool isKeyHold(int key);    //Verifica se uma tecla est� sendo pressionada

        bool isButtonDown(int button);  //Verifica se um bot�o(mouse) foi pressionado
        bool isButtonUp(int button);    //Verifica se um bot�o(mouse) est� solto
        bool isButtonHold(int button);  //Verifica se um bot�o(mouse) est� sendo pressionado

        Point mousePosition();  //Retorna a posi��o do cursor do mouse

        bool isMouseInside(SDL_Rect *rect, float cameraX, float cameraY);   //Verifica se o mouse est� dentro de um ret�ngulo
        bool quitGame();    //Retorna se o jogo foi finalizado
};
