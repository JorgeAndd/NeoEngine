#include "StateManager.h"

int main(int argc, char *argv[]){

    if(SDLBase::initSDL())
    {
        StateManager game;

        game.run();
    }
    SDL_Quit();
    return 0;
}
