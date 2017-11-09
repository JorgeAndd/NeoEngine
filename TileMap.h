#pragma once

#include "TileSet.h"

class TileMap
{
    private:
        std::vector <std::vector <std::vector<int> > > tileMatrix;
        unsigned mapWidth, mapHeight, mapLayers;
        TileSet *tileset;
    public:
        TileMap(unsigned mapWidth, unsigned mapHeight, unsigned tileSize, unsigned mapLayers = 1, TileSet *tileset = NULL); //Construtor a partir de c�digo no GameManager
        TileMap(std::string mapPath, TileSet *tileset = NULL);  //Construtor a partir de arquivo

        void load(std::string mapPath); //Constroi o tilemap a partir da leitura de um arquivo
        void setTileSet(TileSet *tileset); //Define o TileSet utilizado

        int& at(int x, int y, int z = 0);   //Retorna o endere�o de mem�ria de uma certa posi��o do tilemap

        void render(double factor, float cameraX = 0.0, float cameraY = 0.0);    //Renderiza o tilemap. O par�metro factor define o parallax

        unsigned getWidth();    //Retorna a largura do tilemap
        unsigned getHeight();   //Retorna a altura do tilemap
        unsigned getLayers();   //Retorna o n�mero de camadas do tilemap
};
