#pragma once

#include "SDLBase.h"

class Audio
{
    private:
        std::string path;
        Mix_Chunk *sound;
        Mix_Music *music;
        int channel;
    public:
        Audio(std::string path, int type); //Construor. Carrega um arquivo de audio. Type: 0 para música, 1 para som
        ~Audio();   //Destrutor

        void play(int n_loops = 0); //Toca um som. Quando n_loops = -1 o som tocará infinitamente
        void stop(int fade_time = 0);    //Interrompe a execução de um som, com efeito de fade durante fade_time segundos

        void changeVolume(int volume);  //Incrementa o hp da nave por hp_change
};

