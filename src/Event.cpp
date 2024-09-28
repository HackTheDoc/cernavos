#include "include/Event.h"

#include "include/Application.h"
#include "include/Window.h"

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
    
    case UNKNOWN:
    default:
        break;
    }
}  
