#include "include/Application.h"

#include "include/Window.h"

const std::string Application::TITLE = "Cernavos";
bool Application::isRunning = false;

Window Application::window;;

Application::Application()
    : FPS(60)
    , FRAME_DELAY(1000/60)
    , frameStart(0)
    , frameTime(0)
    {}  
Application::~Application() {}  

bool Application::start() {
    isRunning = window.init() == 0;
    
    return isRunning;
} 

void Application::run() {
    frameStart = SDL_GetTicks();

    window.handleEvents();
    window.update();
    window.render();

    frameTime = SDL_GetTicks() - frameStart;
    if (frameTime < FRAME_DELAY)
        SDL_Delay(FRAME_DELAY - frameTime);
} 

void Application::kill() {
    window.kill();
} 

void Application::ReloadWindow() {
    window.reload();
}
