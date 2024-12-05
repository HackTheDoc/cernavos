#pragma once

#include <SDL2/SDL.h>

class UIElement {
public:
    virtual ~UIElement();

    virtual void draw();
    virtual void update();
    virtual void destroy(); 

    /// @brief in pixels with (0,0) being the top left corner
    /// @param x 
    /// @param y 
    void place(const int x, const int y);

    int x();
    int y();
    int width();
    int height();

protected:
    SDL_Rect rect;
};
