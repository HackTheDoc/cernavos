#include "include/Window.h"
#include "include/Application.h"

#include "include/WindowStates/WindowStates.h"

SDL_Renderer* Window::renderer = nullptr;
SDL_Rect Window::screen = { 0, 0, 1280, 720};

Manager* Window::manager = nullptr;
Event Window::event;

Window::Window() {} 

Window::~Window() {} 

int Window::init() {
    // init SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        return -1;
    
    if (TTF_Init() != 0)
        return -1;

    // init window
    window = SDL_CreateWindow(
        Application::TITLE.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        screen.w,
        screen.h,
        SDL_WINDOW_SHOWN
    );
    if (!window) return -2;

    // init renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) return -3;

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    Manager::SetRenderDrawColor(hue::background);

    // init components

    manager = new Manager();

    openMainMenu();

    return 0;
} 

void Window::update() {
    manager->updateCurrentState();
} 

void Window::render() {
    SDL_RenderClear(renderer);

    manager->renderCurrentState();

    SDL_RenderPresent(renderer);
}  

void Window::handleEvents() {
    SDL_PollEvent(&event.e);

    switch (event.e.type) {
    case SDL_QUIT:
        event.raise(Event::ID::QUIT);
        break;
    default:
        event.handleKeyboardInputs();
        break;
    }  
} 

void Window::kill() {
    delete manager;
    manager = nullptr;

    SDL_DestroyRenderer(renderer);
    renderer = nullptr;

    SDL_DestroyWindow(window);
    window = nullptr;

    TTF_Quit();
    SDL_Quit();
} 

void Window::openMainMenu() {
    manager->clearWindowStates();

    manager->addAndUseWindowState(WindowState::ID::MAIN, new MainMenu());
}
