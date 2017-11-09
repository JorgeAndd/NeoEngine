#include "TileSet.h"

TileSet::TileSet(std::string filePath, unsigned tileWidth, unsigned tileHeight) : tileWidth(tileWidth), tileHeight(tileHeight)
{
    tileSet = new Sprite(filePath);

    lines = tileSet->getHeight() / tileHeight;
    columns = tileSet->getWidth() / tileWidth;
}

TileSet::TileSet(unsigned Width, unsigned Height)
{
    lines = 0;
    columns = 0;
    tileWidth = Width;
    tileHeight = Height;
    tileSet = NULL;
}

void TileSet::addTile(std::string filePath)
{
    if(!usingSingleFile())
    {
        Sprite *tile = new Sprite(filePath);
        tiles.push_back(tile);
    }
}

void TileSet::render(int index, float posX, float posY)
{
    int column, x, line, y;

    if(usingSingleFile())
    {
        line = index/columns;
        column = index-(line * columns);

        x = column * tileWidth;
        y = line * tileHeight;

        tileSet->clip(x,y,tileWidth,tileHeight);
        tileSet->render(posX, posY);
    }
    else
    {
        tiles[index]->render(posX,posY);
    }
}

bool TileSet::usingSingleFile()
{
    if(tileSet)
        return true;
    else
        return false;
}

int TileSet::getTileHeight()
{
    return tileHeight;
}

int TileSet::getTileWidth()
{
    return tileWidth;
}
