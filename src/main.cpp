#include "include/Application.h"

Application app;

void run_app() {
    if (!app.start())
        exit(EXIT_FAILURE);
    
    while (Application::isRunning)
        app.run();
    
    app.kill();

    exit(EXIT_SUCCESS);
}

#ifdef _WIN32

#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    run_app();
    return 0;
}

#else

int main() {
    run_app();
    return 0;
}

#endif
