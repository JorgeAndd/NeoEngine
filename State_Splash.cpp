#include "State_Splash.h"

void State_Splash::load(int stack)
{
    //Carregamento de Sprites e Animações
    bg = new Sprite("./img/stateMenu.jpg");

    //Carregamento de sons e músicas
    music = new Audio("./sfx/stateGame.mp3",0);
    music->play(-1);

    //Carregamento de textos
    text_start = new Text("./ttf/arial.ttf","(I)niciar jogo", WHITE ,40);
    text_quit = new Text("./ttf/arial.ttf","(S)air do jogo", WHITE ,40);
}

int State_Splash::unload()
{
    delete(bg);
    delete(music);

    delete(text_start);
    delete(text_quit);

    return 0;
}

int State_Splash::update()
{
    InputManager *inst = InputManager::getInstance();

    if(inst->isKeyHold(SDLK_i))
        return 2;

    if(inst->isKeyHold(SDLK_s))
        return 4;

    return 0;
}

void State_Splash::render()
{
    bg->render(0,0);
    text_start->render(-100,-50);
    text_quit->render(-100,0);
}
