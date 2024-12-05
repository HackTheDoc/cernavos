#pragma once

#include <SDL2/SDL.h>

class Window;

class Event {
public:
    enum ID {
        UNKNOWN,

        QUIT,

        OPEN_MAIN_MENU,

        OPEN_GAME,
        
        OPEN_OPTIONS,
        OPEN_GENERAL_SETTINGS,
        OPEN_CONTROLS_SETTINGS,

        OPEN_CREDITS,
        
    };

    SDL_Event e;

    Event();
    ~Event();  

    /// @brief must be executed when initializing the window in order to link the event handler and the window
    /// @param w pointer to the owning window
    void linkTo(Window* w);

    void handleKeyboardInputs();

    void raise(const Event::ID eid); 

    bool mouseClickLeft(const SDL_EventType clickType = SDL_MOUSEBUTTONUP);
    bool mouseClickRight(const SDL_EventType clickType = SDL_MOUSEBUTTONUP);

private:
    Window* w; // owner window;
};
