#pragma once

#include <vector>

#include "Point.h"
#include "Vector.h"

#include "SDLBase.h"

#include "Text.h"
#include "Audio.h"
#include "Timer.h"

#include "InputManager.h"

#include "State.h"

#include "AccObject.h"
#include "FollowerObject.h"
#include "PlanetRed.h"
#include "Moon.h"
#include "Compass.h"

#include "TileMap.h"

class State_Game : public State
{
    private:
        Sprite *bg,*planetSprite,*earthSprite,*moonSprite,*ufoSprite,*compassSprite;
        Animation *shipAnimation, *boomAnimation;

        Audio *music, *boomSound;

        std::vector<Planet*> planetArray;
        Planet *earth;
        Moon *moon;
        AccObject *ship;
        FollowerObject *ufo;
        Compass *compass;

        Point boom;
        Point camera;

        bool boomOn;
        Timer *endTime, *boomTime;

        int returnState; //1 para vitória, 2 para derrota

        TileMap *tilemap;
        TileSet *tileset;

        Text *instruction_ship, *instruction_ufo, *instruction_general;
    public:
        void checkCollisions();
        void addPlanet(Point mouse);
        int processEvents();

        void load(int stack = 0);
        int unload();
        int update();
        void render();
};
