#pragma once

#include <time.h>

#include "SDLBase.h"
#include "InputManager.h"
#include "Timer.h"

#include "State.h"
#include "State_Splash.h"
#include "State_Game.h"
#include "State_End.h"

class StateManager
{
    private:
        InputManager *inst;
        State *currentState;
        Timer timer;
        int stack;
    public:
        enum {STATE, STATE_SPLASH, STATE_GAME, STATE_END, STATE_QUIT};

        StateManager();
        ~StateManager();

        void run();
};
