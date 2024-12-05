#pragma once

#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "hue.h"
#include "WindowStates/WindowState.h"

/// @brief an all-in-one manager (font, texture and window state)
class Manager {
public:
    Manager();
    ~Manager();

    /// @brief Set the window's rendering color
    /// @param c new color
    /// @return previous color
    static SDL_Color SetRenderDrawColor(const SDL_Color& c);

    /* ----- FONT MANAGER ----- */

    /// @brief 
    /// @param id name the font is registered under
    /// @return nullptr if font not found
    TTF_Font* getFont(const std::string& id);

    void reloadFonts();

    /* ----- TEXTURE MANAGER ----- */

    /// @brief draw a texture on the renderer
    /// @param text texture to draw
    /// @param src if NULL, it takes the whole texture
    /// @param dest if NULL, it takes the whole screen
    /// @param flip can flip the texture horizontally and vertically (default: no flip)
    static void Draw(SDL_Texture* text, const SDL_Rect* src, const SDL_Rect* dest, const SDL_RendererFlip flip = SDL_FLIP_NONE);

    /// @brief draw a rect of 1 px on the renderer
    /// @param rect rect to draw (if NULL, nothing will be drawn)
    /// @param color color to use
    static void DrawRect(const SDL_Rect* rect, const SDL_Color& color);

    /// @brief draw a fille rect on the renderer
    /// @param rect rect to draw (if NULL, nothing will be drawn)
    /// @param color color to use
    static void DrawFilledRect(const SDL_Rect* rect, const SDL_Color& color);

    /// @brief 
    /// @param text 
    /// @param font 
    /// @param color use for the font
    /// @param length define a max length in pixels for the generated texture (default: INT16_MAX, 32767)
    /// @param centered can center the text within the texture (default: false, it is left sided)
    /// @return nullptr if texture fail to generate
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
