#pragma once

#include "InputManager.h"

#include "State.h"
#include "Sprite.h"
#include "Audio.h"
#include "Text.h"

class State_End : public State
{
    private:
        Sprite *bg;
        Text *text_end, *instructions_end1,*instructions_end2;
        Audio *music;
    public:
        void load(int stack = 0);
        int unload();
        int update();
        void render();
};
