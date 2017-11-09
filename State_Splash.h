#pragma once

#include "InputManager.h"

#include "State.h"
#include "Sprite.h"
#include "Audio.h"
#include "Text.h"

class State_Splash : public State
{
    private:
        Sprite *bg;
        Text *text_start, *text_quit;
        Audio *music;
    public:
        void load(int stack = 0);
        int unload();
        int update();
        void render();
};
