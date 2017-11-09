#pragma once

#include "SDLBase.h"
#include "Point.h"

class Text
{
    private:
        TTF_Font *font;
        SDL_Surface *textSurface;
        std::string text;
        int ptsize;
        int style;
        SDL_Color color;
        Point textPosition;
    public:
        Text(std::string font_path, std::string text, SDL_Color color = WHITE, int ptsize = 10, int style = 0, int x = 0, int y = 0);
        ~Text();

        void render(float x, float y);

        void setPos(float x, float y);
        void setText(std::string text);
        void setColor(SDL_Color color);
        void setStyle(int style);
        void setSize(int ptsize);
};

