#pragma once

#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "hue.h"
#include "WindowStates/WindowState.h"

class Manager {
public:
    Manager();
    ~Manager();

    /// @brief Set the window's rendering color
    /// @param c new color
    /// @return previous color
    static SDL_Color SetRenderDrawColor(const SDL_Color& c);

    /* ----- FONT MANAGER ----- */

    TTF_Font* getFont(const std::string& id);

    void reloadFonts();

    /* ----- TEXTURE MANAGER ----- */

    static void Draw(SDL_Texture* text, const SDL_Rect* src, const SDL_Rect* dest, const SDL_RendererFlip flip = SDL_FLIP_NONE);

    static void DrawRect(const SDL_Rect* rect, const SDL_Color& color);

    static void DrawFilledRect(const SDL_Rect* rect, const SDL_Color& color);

    static SDL_Texture* GenerateText(const std::string& text, const std::string& font, const SDL_Color& color, const int length = INT16_MAX, const bool centered = false);

    /* ----- WINDOW STATES MANAGER ----- */

    void addWindowState(const WindowState::ID id, WindowState* ws);
    void addAndUseWindowState(const WindowState::ID id, WindowState* ws);
    void removeWindowState(const WindowState::ID id);
    void setCurrentWindowState(const WindowState::ID id);

    void updateCurrentState();
    void renderCurrentState();

    void clearWindowStates();

    WindowState* getState(const WindowState::ID id);
    WindowState* getCurrentState();

    WindowState::ID getCurrentWindowStateID();

private:
    /* ----- FONT MANAGER ----- */

    std::map<std::string, TTF_Font*> fonts;
    
    void loadFonts();
    void clearFonts();

    /* ----- WINDOW STATES MANAGER ----- */

    std::map<WindowState::ID, WindowState*> windowStates;
    WindowState::ID currentWindowState, previousWindowState;
};
