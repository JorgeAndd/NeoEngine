#include "GameManager.h"

GameManager::GameManager()
{
    SDLBase::initSDL();
    srand(time(NULL));

    //Carregamento dos Sprites e Animações
    bg = new Sprite("img/fundo.png");
    planetSprite = new Sprite("img/PlanetaVermelho.png");
    earthSprite = new Sprite("img/PlanetaTerra.png");
    moonSprite = new Sprite("img/Lua.png");
    ufoSprite = new Sprite("img/ufo.png");

    shipAnimation = new Animation("img/NaveSheet.png",50,4);
    boomAnimation = new Animation("img/BoomSheet.png",60,8);

    //Manipulação dos Sprites e Animações
    earthSprite->rotoZoom(0, 3.0, 3.0, 1);
    earth->setHitBall(earth->getHitBall()*3);
    moonSprite->rotoZoom(0, 2, 2, 1);

    //Criação dos objetos
    earth = new Earth(earthSprite, 300, 300);
    moon = new Moon(moonSprite,earth);
    ship = new AccObject(shipAnimation, 0, 0, 20, 50);
    ufo = new FollowerObject(ufoSprite, -100, -100);

    //Criação de tileset e tilemap
    tileset  = new TileSet("img/Tileset.png",TILE_SIZE,TILE_SIZE);
    tilemap = new TileMap(TILEMAP_SIZE, TILEMAP_SIZE, TILE_SIZE,1,tileset);
    tilemap->load("map/tileMap.txt");

    //Inicialiação da câmera
    camera.x = 0;
    camera.y = 0;

    //Outras inicializações
    boom.x = 0;
    boom.y = 0;
    boomOn = false;

}

GameManager::~GameManager()
{
    delete(bg);
    delete(planetSprite);
    delete(earthSprite);
    delete(moonSprite);
    delete(ufoSprite);

    delete(shipAnimation);
    delete(boomAnimation);
}

void GameManager::run()
{
    int next_time;

    next_time = SDL_GetTicks() + TICK_INTERVAL;
    while(!InputManager::getInstance()->quitGame())
    {
        //Processamento do input
        processEvents();

        //Checa colisões
        checkCollisions(TICK_INTERVAL);

        //Atualização dos objetos
        update(TICK_INTERVAL);

        //Renderização
        render();

        //Atualização da tela
        SDLBase::updateScreen();

        //Finaliza o contador de frames e calcula dt
        SDL_Delay(time_left(next_time));
        next_time += TICK_INTERVAL;
    }
}

int GameManager::time_left(int next_time)
{
    int now;

    now = SDL_GetTicks();
    if(next_time <= now)
        return 0;
    else
        return next_time - now;
}

void GameManager::processEvents()
{
    InputManager *inst = InputManager::getInstance();

    inst->update();

//Movimento da terra
    if(inst->isKeyHold(SDLK_UP))
        ship->accelerate(-1);

    if(inst->isKeyHold(SDLK_DOWN))
        ship->accelerate(1);

    if(inst->isKeyHold(SDLK_LEFT))
        ship->rotate(10);

    if(inst->isKeyHold(SDLK_RIGHT))
        ship->rotate(-10);

//Movimento da câmera

    if(inst->isKeyHold(SDLK_w))
        camera.y -= 10;

    if(inst->isKeyHold(SDLK_s))
        camera.y += 10;

    if(inst->isKeyHold(SDLK_a))
        camera.x -= 10;

    if(inst->isKeyHold(SDLK_d))
        camera.x += 10;

//Criação de um PlanetRed
    if(inst->isButtonDown(1))
    {
        Point mousePos;

        mousePos = inst->mousePosition();
        addPlanet(mousePos);
    }

    if(inst->isButtonDown(3))
        if(ufo)
        {
            float posX, posY;
            posX = inst->mousePosition().x + camera.x;
            posY = inst->mousePosition().y + camera.y;
            ufo->enqueue(posX, posY);
        }
}

void GameManager::update(int dt)
{
    if(ship)
    {
        if(ship->getHp() <= 0)
        {
                boom.x = ship->getBox().y;
                boom.y = ship->getBox().x;
                boomOn;
                ship = NULL;
                boomAnimation->update(dt);
        }
        else
            ship->update(dt);
    }

    moon->update(dt);

    if(ufo)
        ufo->update(dt);
    if(boomOn){
        boomAnimation->update(dt);
        if(boomAnimation->getFrame() == 8)
            boomOn = false;
    }

    if(ship && ufo)
    {
        camera.x = ship->getPos().x;
        camera.y = ship->getPos().y;
    }


}

void GameManager::render()
{
    bg->render(0,0);

    tilemap->render(0.3,camera.x,camera.y); //Renderiza o tilemap

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
        boomAnimation->render(boom.x-camera.x, boom.y-camera.y);
}

void GameManager::addPlanet(Point Position)
{
    planetArray.push_back(new PlanetRed(planetSprite, ((rand()%800)-400+camera.x), ((rand()%600)-300+camera.y), rand()%20));
}

void GameManager::checkCollisions(int dt)
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
                ship->changeHp(-1);
                it = planetArray.erase(it);
                --it;
            }
        }

        if(ship->collidesWith(ufo))
            ship->setHp(0);

        if(ship->collidesWith(earth))
        {
            boom.x = ufo->getBox().x;
            boom.y = ufo->getBox().y;
            boomOn = true;
            ufo = NULL;
            boomAnimation -> update(dt);
            return;
        }
    }
}
