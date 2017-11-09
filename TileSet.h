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
        TileSet(std::string filePath, unsigned tileWidth, unsigned tileHeight);   //Construtor para arquivo único de tileset
        TileSet(unsigned tileWidth, unsigned tileHeight); //Construtor para múltiplos arquivos de tileset

        void addTile(std::string filePath); //Adiciona um tile no vetor de tiles(para caso de uso de múltiplos arquivos)
        void render(int index, float posX, float posY); //Renderiza um tile na posição dada

        bool usingSingleFile(); //Retorna TRUE se está usando apenas um arquivo
        int getTileWidth();
        int getTileHeight();
};
