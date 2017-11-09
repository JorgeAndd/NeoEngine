#include "State_End.h"

#define VITORIA 1
#define DERROTA 2

void State_End::load(int stack)
{
    if(stack == VITORIA) //Vitória
    {
        //Carregamento de Sprites e Animações
        bg = new Sprite("./img/stateWin.jpg");

        //Carregamento de sons e músicas
        music = new Audio("./sfx/stateWin.mp3",0);
        music->play(-1);

        //Carregamento de textos
        text_end = new Text("./ttf/arial.ttf","Você venceu!",WHITE,50);
    }else if(stack == DERROTA) //Derrota
    {
        //Carregamento de Sprites e Animações
        bg = new Sprite("./img/stateLose.jpg");

        //Carregamento de sons e músicas
        music = new Audio("./sfx/stateLose.mp3",0);
        music->play(-1);

        //Carregamento de textos
        text_end = new Text("./ttf/arial.ttf","Você perdeu",WHITE,50);
    }
    instructions_end1 = new Text("./ttf/arial.ttf","Esc: Sair",WHITE,20);
    instructions_end2 = new Text("./ttf/arial.ttf","Enter: Recomeçar",WHITE,20);
}

int State_End::unload()
{
    delete(instructions_end1);
    delete(instructions_end2);

    delete(text_end);

    delete(music);

    delete(bg);

    return 0;
}

int State_End::update()
{
    InputManager *inst = InputManager::getInstance();

    if(inst->isKeyHold(SDLK_RETURN))
        return 1;

    return 0;
}

void State_End::render()
{
    bg->render(0,0);
    text_end->render(-100,-50);

    instructions_end1->render(-400,-300);
    instructions_end2->render(-400,-280);
}
