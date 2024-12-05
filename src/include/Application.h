#pragma once

#include <string>
#include <cstdint>

typedef uint32_t Uint32;

class Window;

class Application{
public:
    static const std::string TITLE;
    static const std::string VERSION;
    static bool isRunning;

    Application();
    ~Application();

    bool start();
    void run();
    void kill();

    static void ReloadWindow();

private:
    static Window window;

    const int FPS;
    const int FRAME_DELAY;

    Uint32 frameStart;
    int frameTime;
};
