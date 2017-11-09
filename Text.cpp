#include "Text.h"

Text::Text(std::string font_path, std::string text,  SDL_Color color, int ptsize, int style, int x, int y)
    :text(text), ptsize(ptsize),style(style),color(color)
{
    font = TTF_OpenFont(font_path.c_str(), ptsize);
    textSurface = TTF_RenderText_Blended(font, text.c_str(), color);
    textPosition.x = x;
    textPosition.y = y;
}
Text::~Text()
{
    TTF_CloseFont(font);
    SDL_FreeSurface(textSurface);
}

void Text::render(float x, float y)
{
    SDL_Rect dst;

    dst.h = 0;
    dst.w = 0;
    dst.x = x;
    dst.y = y;

    SDLBase::renderSurface(textSurface, NULL, &dst);
}
void Text::setPos(float x, float y)
{
    textPosition.x = x;
    textPosition.y = y;
}

void Text::setText(std::string text)
{
    SDL_FreeSurface(textSurface);
    this->text = text;
    textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
}

void Text::setColor(SDL_Color color)
{
    this->color = color;
}

void Text::setStyle(int style)
{
    SDL_FreeSurface(textSurface);
    this->style = style;
    textSurface = TTF_RenderText_Blended(font, text.c_str(), color);
}

void Text::setSize(int ptsize)
{
    this->ptsize = ptsize;
}
