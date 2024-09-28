#pragma once

#include <SDL2/SDL.h>

class Window;

class Event {
public:
    enum ID {
        UNKNOWN,

        QUIT,
    };

    SDL_Event e;

    Event();
    ~Event();  

    void linkTo(Window* w);

    void handleKeyboardInputs();

    void raise(const Event::ID eid); 

private:
    Window* w; // owner window;
};
