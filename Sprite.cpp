#include "Sprite.h"

Sprite::Sprite(std::string path)
{
    surface = NULL;
    surfaceRotoZoom = NULL;
    angle = 0;
    scaleX = 1.0;
    scaleY = 1.0;

    load(path);
}

Sprite::~Sprite()
{
    if(surface != NULL)
    {
        SDL_FreeSurface(surface);
        surface = NULL;
    }

    if(surfaceRotoZoom != NULL)
    {
        SDL_FreeSurface(surfaceRotoZoom);
        surfaceRotoZoom = NULL;
    }

}

void Sprite::load(std::string path)
{
    if(surface != NULL)
        SDL_FreeSurface(surface);

    surface = SDLBase::loadImage(path);
    clipRect.x = 0;
    clipRect.y = 0;
    clipRect.w = surface->w;
    clipRect.h = surface->h;
}

void Sprite::clip(int x, int y, int w, int h)
{
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::render(int x, int y)
{
    SDL_Rect dst;

    if(surfaceRotoZoom)
    {
        dst.x = x - (surfaceRotoZoom->w/2);
        dst.y = y - (surfaceRotoZoom->h/2);

        SDLBase::renderSurface(surfaceRotoZoom, NULL, &dst);
    }else{
        dst.x = x - (surface->w/2);
        dst.y = y - (surface->h/2);

        SDLBase::renderSurface(surface, &clipRect, &dst);
    }
}

void Sprite::rotoZoom(float rotation, float zoomX, float zoomY, bool force)
{
    if((rotation != angle) || (zoomX != scaleX) || (zoomY != scaleY) || force)
    {
        if(surfaceRotoZoom)
            restore();

        scaleX = zoomX;
        scaleY = zoomY;
        angle = rotation;

        if((clipRect.x != 0) || (clipRect.y != 0) || (clipRect.h != surface->h) || (clipRect.w != surface->w))
        {
            SDL_Rect rect;

            rect.x = clipRect.x;
            rect.y = clipRect.y;
            rect.h = clipRect.h;
            rect.w = clipRect.w;

            SDL_Surface *surfaceAux = SDLBase::clip(surface,&rect);

            surfaceRotoZoom = SDLBase::rotoZoom(surfaceAux, angle, scaleX, scaleY);
            SDL_FreeSurface(surfaceAux);
        }
        else
            surfaceRotoZoom = SDLBase::rotoZoom(surface, angle, scaleX, scaleY);
    }
}

void Sprite::restore()
{
    SDL_FreeSurface(surfaceRotoZoom);
}

int Sprite::getWidth()
{
    return surface->w;
}

int Sprite::getHeight()
{
    return surface->h;
}

SDL_Rect Sprite::getClip()
{
    return clipRect;
}

SDL_Surface* Sprite::getSurface()
{
    return surface;
}

SDL_Surface* Sprite::getRotoZoom()
{
    return surfaceRotoZoom;
}

float Sprite::getScaleX()
{
    return scaleX;
}

float Sprite::getScaleY()
{
    return scaleY;
}
