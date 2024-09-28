#pragma once

#include "Event.h"
#include "Manager.h"

class Window {
public:
    static SDL_Renderer* renderer;
    static SDL_Rect screen;

    static Manager* manager;
    static Event event;

    Window();
    ~Window();

    int init();
    void update();
    void render();
    void handleEvents();
    void kill(); 

    void openMainMenu();

private:
    SDL_Window* window; // actual window object
};
