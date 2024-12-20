#include "include/Event.h"

#include "include/Application.h"
#include "include/Window.h"

#include <iostream>

Event::Event() {}   

Event::~Event() {} 

void Event::linkTo(Window* w) {
    this->w = w;
} 

void Event::handleKeyboardInputs() {

} 

void Event::raise(const Event::ID eid) {
    switch (eid) {
    case QUIT:
        Application::isRunning = false;
        break;

    case OPEN_MAIN_MENU:
        w->openMainMenu();
        break;

    case OPEN_GAME:
        std::cout << "opening game..." << std::endl;
        break;
    
    case OPEN_OPTIONS:
        w->openOptionsMenu();
        break;
    case OPEN_GENERAL_SETTINGS:
        w->openOptionsPage(0);
        break;
    case OPEN_CONTROLS_SETTINGS:
        w->openOptionsPage(1);
        break;

    case OPEN_CREDITS:
        std::cout << "opening credits..." << std::endl;
        break;

    case UNKNOWN:
    default:
        break;
    }
}  

bool Event::mouseClickLeft(const SDL_EventType clickType) {
    return e.type == clickType && e.button.button == SDL_BUTTON_LEFT;
}

bool Event::mouseClickRight(const SDL_EventType clickType) {
    return e.type == clickType && e.button.button == SDL_BUTTON_RIGHT;
}
