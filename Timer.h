#pragma once

#include "SDLBase.h"


class Timer
{
    private:
        int initialTime;
        int pauseTime;
        bool paused;
    public:
        Timer();    //Inicializa o contador

        void restart();  //Reinicia o contador
        void pause();    //Pausa o contador
        void resume();   //Resume o contador, quando pausado

        float getTime(); //Retorna o tempo, em segundos
};
