#pragma once

#include <vector>
#include <math.h>

#include "Sprite.h"

class TileSet
{
    private:
        unsigned tileWidth, tileHeight;
        unsigned lines, columns;
        Sprite *tileSet;
        std::vector<Sprite*> tiles;
        SDL_Rect *dstRect;
    public:
        TileSet(std::string filePath, unsigned tileWidth, unsigned tileHeight);   //Construtor para arquivo �nico de tileset
        TileSet(unsigned tileWidth, unsigned tileHeight); //Construtor para m�ltiplos arquivos de tileset

        void addTile(std::string filePath); //Adiciona um tile no vetor de tiles(para caso de uso de m�ltiplos arquivos)
        void render(int index, float posX, float posY); //Renderiza um tile na posi��o dada

        bool usingSingleFile(); //Retorna TRUE se est� usando apenas um arquivo
        int getTileWidth();
        int getTileHeight();
};
