#pragma once

#include <string>
#include <SDL2/SDL.h>

#include "hue.h"

class Manager {
public:
    Manager();
    ~Manager();

    /// @brief Set the window's rendering color
    /// @param c new color
    /// @return previous color
    static SDL_Color SetRenderDrawColor(const SDL_Color& c);   
};
