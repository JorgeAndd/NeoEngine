#include "TileMap.h"

TileMap::TileMap(unsigned mapWidth, unsigned mapHeight, unsigned tileSize, unsigned mapLayers, TileSet *tileset) :
    mapWidth(mapWidth), mapHeight(mapHeight), mapLayers(mapLayers), tileset(tileset)
{
    //Redimensiona X
    tileMatrix.resize(mapWidth);
    //Redimensiona Y
    for(unsigned x=0; x<mapWidth; x++)
        tileMatrix[x].resize(mapHeight);
    //Redimensiona Z
    for(unsigned x=0; x<mapWidth; x++)
        for(unsigned y=0; y<mapHeight; y++)
            tileMatrix[x][y].resize(mapLayers);

    //Zera o tilemap
    for(unsigned x=0; x<mapWidth; x++)
        for(unsigned y=0; y<mapHeight; y++)
            for(unsigned z=0; z<mapLayers; z++)
                tileMatrix[x][y][z] = -1;
}

TileMap::TileMap(std::string mapPath, TileSet *tileset) : tileset(tileset)
{
    mapWidth = 0;
    mapHeight = 0;
    mapLayers = 0;

    load(mapPath);
}

void TileMap::load(std::string mapPath)
{
    FILE *tileMap;
    int tile;

    tileMap = fopen(mapPath.c_str(),"r");

    fscanf(tileMap,"%2d",&mapWidth);
    fgetc(tileMap);
    fscanf(tileMap,"%2d",&mapHeight);
    fgetc(tileMap);
    fscanf(tileMap,"%2d",&mapLayers);
    fgetc(tileMap);

    for(unsigned l=0;l<mapLayers;l++)
        for(unsigned h=0;h<mapHeight;h++)
            for(unsigned w=0;w<mapWidth;w++)
            {
                fscanf(tileMap,"%2d",&tile);
                this->at(w,h,l) = tile-1;
                fgetc(tileMap);
            }
}

void TileMap::setTileSet(TileSet *tileset)
{
    this->tileset = tileset;
}

int& TileMap::at(int x, int y, int z)
{
    return tileMatrix[x][y][z];
}

void TileMap::render(double factor, float cameraX, float cameraY)
{
    if(tileset){
        for(unsigned z=0; z<mapLayers; z++)
            for(unsigned x=0; x<mapWidth; x++)
                for(unsigned y=0; y<mapHeight; y++)
                    if(tileMatrix[x][y][z] > -1)
                        tileset->render(tileMatrix[x][y][z], (x * tileset->getTileWidth())-cameraX*((z+1)*factor), y * tileset->getTileHeight()-cameraY*((z+1)*factor));
    }
}

unsigned TileMap::getWidth()
{
    return mapWidth;
}

unsigned TileMap::getHeight(){
    return mapHeight;
}

unsigned TileMap::getLayers(){
    return mapLayers;
}
