#include "include/Application.h"

Application app;

int main() {
    if (!app.start())
        return 1;
    
    while (Application::isRunning)
        app.run();
    
    app.kill();

    return 0;
} 
