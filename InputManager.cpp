#include "InputManager.h"

InputManager *InputManager::instance = NULL;

InputManager::InputManager()
{
    event = new SDL_Event;

    memset(keyState, false, sizeof(bool)*N_KEYS);
    memset(keyChanged, false, sizeof(bool)*N_KEYS);
    memset(mouseState, false, sizeof(bool)*N_MOUSE_BUTTONS);
    memset(mouseChanged, true, sizeof(bool)*N_MOUSE_BUTTONS);
    quit = false;

    update();
}

InputManager* InputManager::getInstance()
{
    if(!instance)   instance = new InputManager();

    return instance;
}

void InputManager::update()
{
    memset(keyChanged, false, sizeof(bool)*N_KEYS);
    memset(mouseChanged, false, sizeof(bool)*N_MOUSE_BUTTONS);

    while(SDL_PollEvent(event))
    {
        switch(event->type)
        {
        case SDL_KEYDOWN:
            keyState[event->key.keysym.sym] = true;
            keyChanged[event->key.keysym.sym] = true;
            break;
        case SDL_KEYUP:
            keyState[event->key.keysym.sym] = false;
            keyChanged[event->key.keysym.sym] = true;
            break;
        case SDL_MOUSEMOTION:
            mouseX = event->motion.x;
            mouseY = event->motion.y;
            break;
        case SDL_MOUSEBUTTONDOWN:
            mouseState[event->button.button] = true;
            mouseChanged[event->button.button] = true;
            break;
        case SDL_MOUSEBUTTONUP:
            mouseState[event->button.button] = false;
            mouseChanged[event->button.button] = true;
            break;
        case SDL_QUIT:
            quit = true;
            break;
        default:
            break;
        }
    }


    if(isKeyDown(SDLK_ESCAPE))
    {
        quit = true;
    }
}

bool InputManager::isKeyDown(int key)
{
    return (keyState[key] && keyChanged[key]);
}

bool InputManager::isKeyUp(int key)
{
    return (!keyState[key] && keyChanged[key]);
}

bool InputManager::isKeyHold(int key){
    return keyState[key];
}

bool InputManager::isButtonDown(int button)
{
    return (mouseState[button] && mouseChanged[button]);
}

bool InputManager::isButtonUp(int button)
{
    return (!mouseState[button] && mouseChanged[button]);
}

bool InputManager::isButtonHold(int button)
{
    return mouseState[button];
}

Point InputManager::mousePosition()
{
    Point mousePosition;

    mousePosition.x = mouseX - 400;
    mousePosition.y = mouseY - 300;

    return mousePosition;
}

bool InputManager::isMouseInside(SDL_Rect *rect, float cameraX, float cameraY)
{
    if (mouseX - cameraX >= rect->x && mouseX - cameraX < (rect->x + rect->w))
    {
        if (mouseY - cameraY >= rect->y && mouseY - cameraY < (rect->y + rect->h))
        {
            return true;
        }
    }

    return false;
}

bool InputManager::quitGame()
{
    return quit;
}
