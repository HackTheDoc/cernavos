#include "include/Manager.h"

#include "include/Window.h"


Manager::Manager() {}

Manager::~Manager() {}  

SDL_Color Manager::SetRenderDrawColor(const SDL_Color& c) {
    SDL_Color t;
    SDL_GetRenderDrawColor(Window::renderer, &t.r, &t.g, &t.b, &t.a);

    SDL_SetRenderDrawColor(Window::renderer, c.r, c.g, c.b, c.a);

    return t;
}   
