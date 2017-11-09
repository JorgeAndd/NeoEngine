#include "Timer.h"

Timer::Timer()
{
    initialTime = SDL_GetTicks();
    paused = false;
}

void Timer::restart()
{
    initialTime = SDL_GetTicks();
    paused = false;
}

void Timer::pause()
{
    pauseTime = SDL_GetTicks();
    paused = true;
}

void Timer::resume()
{
    initialTime += SDL_GetTicks() - pauseTime;
    paused = false;
}

float Timer::getTime()
{
    if(paused)
        return (pauseTime - initialTime)/1000.f;
    else
        return (SDL_GetTicks() - initialTime)/1000.f;
}
