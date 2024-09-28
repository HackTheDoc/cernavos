#pragma once

#include <SDL2/SDL.h>

class Window;

class Event {
public:
    enum ID {
        UNKNOWN,

        QUIT,

        OPEN_GAME,
        OPEN_OPTIONS,
        OPEN_CREDITS,
    };

    SDL_Event e;

    Event();
    ~Event();  

    void linkTo(Window* w);

    void handleKeyboardInputs();

    void raise(const Event::ID eid); 

    bool mouseClickLeft(const SDL_EventType clickType = SDL_MOUSEBUTTONUP);
    bool mouseClickRight(const SDL_EventType clickType = SDL_MOUSEBUTTONUP);

private:
    Window* w; // owner window;
};
