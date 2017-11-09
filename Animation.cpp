#include "Animation.h"

Animation::Animation(std::string path, float duration, int n_sprites) : Sprite(path), n_sprites(n_sprites)
{
    clipRect.x = 0;
    clipRect.y = 0;
    clipRect.w = (surface->w)/n_sprites;
    clipRect.h = surface->h;

    time = 0;
    setDuration(duration);
}

void Animation::update()
{
    time += TIME_STEP;

    if (time >= frameTime * n_sprites)
        time -= frameTime * n_sprites;

    clip(clipRect.w * (int)(time / frameTime), clipRect.y, clipRect.w, clipRect.h);
}

void Animation::render(int x, int y)
{
    SDL_Rect dst;

    dst.h = 0;
    dst.w = 0;

    if(surfaceRotoZoom)
    {
        dst.x = x - (surfaceRotoZoom->w/2);
        dst.y = y - (surfaceRotoZoom->h/2);

        SDLBase::renderSurface(surfaceRotoZoom, NULL, &dst);
    }else{
        dst.x = x - (surface->w/(2*n_sprites));
        dst.y = y - (surface->h/2);

        SDLBase::renderSurface(surface, &clipRect, &dst);
    }
}

void Animation::setFrame(int frame)
{
    time = frame * frameTime;
}

void Animation::setDuration(float time)
{
    frameTime = time / n_sprites;
}

float Animation::getDuration()
{
    return frameTime * n_sprites;
}

int Animation::getFrame()
{
    return time / frameTime;
}

