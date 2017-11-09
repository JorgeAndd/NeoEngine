#include "StateManager.h"

StateManager::StateManager()
{
    SDLBase::initSDL();
    inst = InputManager::getInstance();


    currentState = new State_Splash();
    currentState->load();

    srand(time(NULL));

    inst->update();
    stack = 0;
}

StateManager::~StateManager()
{
    SDLBase::exitSDL();
    currentState->unload();
    free(currentState);
}

void StateManager::run()
{
    bool quit = false;
    float accumulator, lastTime;
    const float dt = TIME_STEP;

    lastTime = SDL_GetTicks()/1000.f;
    accumulator = 0.f;

    while(!quit)
    {
        float nowTime = SDL_GetTicks()/1000.f;
        float frameTime = nowTime - lastTime;
        lastTime = nowTime;
        accumulator += frameTime;

        if(accumulator >= dt)
        {
            inst->update();
            if(inst->quitGame())
            {
                 quit = true;
                 continue;
            }

            switch(currentState->update())
            {
                case STATE:
                    break;
                case STATE_SPLASH:
                    stack = currentState->unload();
                    delete(currentState);
                    currentState = new State_Splash();
                    currentState->load(stack);
                    break;
                case STATE_GAME:
                    stack = currentState->unload();
                    delete(currentState);
                    currentState = new State_Game();
                    currentState->load(stack);
                    break;
                case STATE_END:
                    stack = currentState->unload();
                    delete(currentState);
                    currentState = new State_End();
                    currentState->load(stack);
                    break;
                case STATE_QUIT:
                    quit = true;
                    break;
            }
            accumulator -= dt;
        }

        currentState->render();
        SDLBase::updateScreen();

        /*
        now = SDL_GetTicks();
        if(next_time > now)
            SDL_Delay(next_time - now);
        next_time += TICK_INTERVAL;
        */
    }
}
