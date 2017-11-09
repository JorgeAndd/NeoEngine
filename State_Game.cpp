#include "State_Game.h"

#include <Windows.h>

#define VITORIA 1
#define DERROTA 2

void State_Game::load(int stack)
{
    //Carregamento dos Sprites e Animações
    bg = new Sprite("./img/fundo.png");
    planetSprite = new Sprite("./img/PlanetaVermelho.png");
    earthSprite = new Sprite("./img/PlanetaTerra.png");
    moonSprite = new Sprite("./img/Lua.png");
    ufoSprite = new Sprite("./img/ufo.png");
    compassSprite = new Sprite("./img/compass.png");

    shipAnimation = new Animation("./img/NaveSheet.png",1.f,4);
    boomAnimation = new Animation("./img/BoomSheet.png",1.5,8);

    //Carregamento de sons e músicas
    music = new Audio("./sfx/stateGame.mp3",0);
    music->changeVolume(-30);
    music->play(-1);
    boomSound = new Audio("./sfx/boom.wav",1);

    //Manipulação dos Sprites e Animações
    earthSprite->rotoZoom(0, 3.0, 3.0, 1);
    moonSprite->rotoZoom(0, 2, 2, 1);

    //Criação dos objetos
    earth = new Planet(earthSprite, (rand()%5000)-2500,(rand()%5000)-2500);
    //earth = new Planet(earthSprite, 0, -300);
    earth->changeHitBall(2.5);
    moon = new Moon(moonSprite,earth);
    ship = new AccObject(shipAnimation, 0, 0, 20, 1000);
    ufo = new FollowerObject(ufoSprite, -100, -100);
    compass = new Compass(compassSprite);

    //Criação de tileset e tilemap
    tileset  = new TileSet("./img/Tileset.png",TILE_SIZE,TILE_SIZE);
    tilemap = new TileMap(TILEMAP_SIZE, TILEMAP_SIZE, TILE_SIZE,1,tileset);
    tilemap->load("./map/tileMap.txt");

    //Criação de textos
    instruction_ufo = new Text("./ttf/arial.ttf","UFO :: Botão direito: Mover  Botão esquerdo: Criar planeta",WHITE,15);
    instruction_ship = new Text("./ttf/arial.ttf","NAVE :: Setas: Mover",WHITE,15);
    instruction_general = new Text("./ttf/arial.ttf","Backspace: Voltar ao menu",WHITE,20);

    //Inicialiação da câmera
    camera.x = 0;
    camera.y = 0;

    //Outras inicializações
    boom.x = 0;
    boom.y = 0;
    boomOn = false;

    endTime = new Timer();
    boomTime = new Timer();
}

int State_Game::unload()
{
    delete(instruction_general);
    delete(instruction_ship);
    delete(instruction_ufo);

    delete(tilemap);
    delete(tileset);

    delete(compass);
    delete(ufo);
    delete(ship);
    delete(moon);
    delete(earth);

    delete(boomSound);
    music->changeVolume(30);
    delete(music);

    delete(boomAnimation);
    delete(shipAnimation);

    delete(ufoSprite);
    delete(moonSprite);
    delete(earthSprite);
    delete(planetSprite);
    delete(bg);

    return returnState;
}

int State_Game::update()
{
    if(processEvents() == 1)
        return 1;

    checkCollisions();

    moon->update();

    if(ship)
    {
        if(ship->getHp() <= 0)
        {
                returnState = DERROTA;
                endTime->restart();
                ship = NULL;
                boomAnimation->update();
        }
        else
            ship->update();
    }

    if(ufo)
        ufo->update();

    if(ship && ufo)
    {
        Point shipLoc, earthLoc;

        shipLoc = ship->getPos();
        earthLoc = earth->getPos();

        camera = shipLoc;

        compass->update(shipLoc, earthLoc);
    }

    if(boomOn){
        boomAnimation->update();
        if(boomTime->getTime() >= 1.5)
        {
            boomOn = false;
            boomTime->restart();
        }
    }

    if(returnState != 0)
    {
        if(endTime->getTime() >= 2)
        {
            endTime->restart();
            return 3;
        }
    }

    return 0;
}

int State_Game::processEvents()
{
    InputManager *inst = InputManager::getInstance();

//Movimento da nave
    if(ship)
    {
        if(inst->isKeyHold(SDLK_UP))
            ship->accelerate();

        if(inst->isKeyHold(SDLK_LEFT))
            ship->setAngularSpeed(-PI/2);
        else if(inst->isKeyHold(SDLK_RIGHT))
            ship->setAngularSpeed(PI/2);
        else
            ship->setAngularSpeed(0.f);
    }


//Criação de um PlanetRed
    if(inst->isButtonDown(SDL_BUTTON_LEFT))
    {
        Point mousePos;

        mousePos = inst->mousePosition();
        addPlanet(mousePos);
    }

//Movimento do UFO
    if(ufo)
        if(inst->isButtonDown(SDL_BUTTON_RIGHT))
        {
            Point position;

            position = inst->mousePosition();
            //position += camera;
            position.x += camera.x;
            position.y += camera.y;

            ufo->enqueue(position);
        }

//Retorna para o menu
    if(inst->isKeyHold(SDLK_BACKSPACE))
        return 1;

    return 0;
}


void State_Game::render()
{
    bg->render(0,0);

    tilemap->render(0.5,camera.x,camera.y); //Renderiza o tilemap

    for(unsigned i=0; i<planetArray.size(); i++)
    {
        //Renderiza todos os planets de planetArray
        planetArray[i]->render(camera.x,camera.y);
    }

    earth->render(camera.x,camera.y);
    moon->render(camera.x,camera.y);

    if(ship)
        ship->render(camera.x,camera.y);

    if(ufo)
    {
        ufo->render(camera.x,camera.y);
        ufo->renderQueueLines(camera.x,camera.y);
    }

    if(boomOn)
        boomAnimation->render(boom.x - camera.x, boom.y - camera.y);

    compass->render(0,-250);

    instruction_ufo->render(-400,-300);
    instruction_ship->render(-400,-280);
    instruction_general->render(150,280);
}

void State_Game::addPlanet(Point position)
{
    planetArray.push_back(new PlanetRed(planetSprite, position.x+camera.x, position.y+camera.y));
}

void State_Game::checkCollisions()
{
    Planet *planetaux;

    if(ufo && ship)
    {
        for(std::vector<Planet*>::iterator it=planetArray.begin(); it!=planetArray.end(); ++it){
            planetaux = *it;
            if(ship->collidesWith(planetaux))
            {
                boom.x = planetaux->getBox().x;
                boom.y = planetaux->getBox().y;
                boomOn = true;
                boomSound->play();
                boomTime->restart();

                ship->changeHp(-1);

                it = planetArray.erase(it);
                --it;
            }
        }

        if(ship->collidesWith(ufo))
        {
            boom.x = ship->getBox().x;
            boom.y = ship->getBox().y;
            boomOn = true;
            boomSound->play();
            boomTime->restart();

            ship->setHp(0);
        }

        if(ship->collidesWith(earth))
        {
            boom.x = ufo->getBox().x;
            boom.y = ufo->getBox().y;
            boomOn = true;
            boomSound->play();
            boomTime->restart();


            ufo = NULL;

            endTime->restart();
            returnState = 1;
            return;
        }
    }
}
