#pragma once

#include "Event.h"
#include "Manager.h"

/// @brief Describe the window of an application (require an associated Application object in order to work)
class Window {
public:
    static SDL_Renderer* renderer;
    static SDL_Rect screen;

    static Manager* manager;
    static Event event;

    static bool fullscreen;

    Window();
    ~Window();

    /// @brief initialize libraries and components needed for the window
    /// @return
    /// - 0: no problem during initialization
    ///
    /// - -1: a SDL library generated an error
    ///
    /// - -2: could not create sdl window object
    ///
    /// - -3: could not create renderer
    int init();
    /// @brief update only the current state of the indow
    void update();
    /// @brief process the rendering of the current state
    void render();
    /// @brief handle user events such as keyboard inputs
    void handleEvents();
    /// @brief ensure every loaded components is unloaded
    void kill(); 

    /// @brief open window state for main menu
    void openMainMenu();

    /// @brief open window state for options menu
    void openOptionsMenu();
    /// @brief open an options page
    /// @param page format [GENERAL, CONTROLS]
    void openOptionsPage(const int page);
    
    /// @brief reload the window to update fullscreen status
    void reload();

private:
    SDL_Window* window; // actual window object
};
