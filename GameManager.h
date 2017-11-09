#pragma once

#include <time.h>
#include <vector>

#include "Point.h"
#include "Vector.h"

#include "SDLBase.h"

#include "Text.h"
#include "Sprite.h"
#include "Animation.h"

#include "InputManager.h"

#include "AccObject.h"
#include "FollowerObject.h"
#include "PlanetRed.h"
#include "Earth.h"
#include "Moon.h"

#include "TileMap.h"

#define SCROLL 20.0f
#define TILEMAP_SIZE 16
#define TILE_SIZE 75
#define N_TEXTURES 30
#define TICK_INTERVAL 60

class GameManager
{
    private:
        Sprite *bg,*planetSprite,*earthSprite,*moonSprite,*ufoSprite;
        Animation *shipAnimation, *boomAnimation;


        std::vector<Planet*> planetArray;
        Earth *earth;
        Moon *moon;
        AccObject *ship;
        FollowerObject *ufo;

        Point boom;
        Point camera;

        bool boomOn;

        TileMap *tilemap;
        TileSet *tileset;
    public:
        GameManager();
        ~GameManager();

        void run();
        int time_left(int);
        void processEvents();
        void update(int dt);
        void render();
        void checkCollisions(int dt);

        void addPlanet(Point mouse);
};
