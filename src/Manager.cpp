#include "include/Manager.h"

#include "include/Window.h"

Manager::Manager() {
    loadFonts();

    currentWindowState = WindowState::ID::UNKNOWN;
}

Manager::~Manager() {
    clearFonts();
    clearWindowStates();
}  

SDL_Color Manager::SetRenderDrawColor(const SDL_Color& c) {
    SDL_Color t;
    SDL_GetRenderDrawColor(Window::renderer, &t.r, &t.g, &t.b, &t.a);

    SDL_SetRenderDrawColor(Window::renderer, c.r, c.g, c.b, c.a);

    return t;
}   

/* ----- FONT MANAGER ----- */

TTF_Font* Manager::getFont(const std::string& id){
    if (fonts.count(id) == 0)
        return nullptr;
    return fonts[id];
}

void Manager::loadFonts() {
    fonts["h1"]         = TTF_OpenFont("./assets/font/Oxanium-Regular.ttf"  , 160*(Window::fullscreen+1));
    fonts["h2"]         = TTF_OpenFont("./assets/font/Oxanium-Regular.ttf"  , 120*(Window::fullscreen+1));
    fonts["h2 bold"]    = TTF_OpenFont("./assets/font/Oxanium-Bold.ttf"     , 120*(Window::fullscreen+1));
    fonts["h3"]         = TTF_OpenFont("./assets/font/Oxanium-Regular.ttf"  ,  76*(Window::fullscreen+1));
    fonts["h3 bold"]    = TTF_OpenFont("./assets/font/Oxanium-Bold.ttf"     ,  76*(Window::fullscreen+1));
    fonts["h4"]         = TTF_OpenFont("./assets/font/Oxanium-Regular.ttf"  ,  64*(Window::fullscreen+1));
    fonts["h4 bold"]    = TTF_OpenFont("./assets/font/Oxanium-Bold.ttf"     ,  64*(Window::fullscreen+1));

    fonts["big"]            = TTF_OpenFont("./assets/font/Oxanium-Regular.ttf"  , 48*(Window::fullscreen+1));
    fonts["big bold"]       = TTF_OpenFont("./assets/font/Oxanium-Bold.ttf"     , 48*(Window::fullscreen+1));
    fonts["default"]        = TTF_OpenFont("./assets/font/Oxanium-Regular.ttf"  , 32*(Window::fullscreen+1));
    fonts["default bold"]   = TTF_OpenFont("./assets/font/Oxanium-Bold.ttf"     , 32*(Window::fullscreen+1));
    fonts["small"]          = TTF_OpenFont("./assets/font/Oxanium-Regular.ttf"  , 16*(Window::fullscreen+1));
}

void Manager::clearFonts() {
    for (std::pair<const std::string, TTF_Font*> f : fonts)
        TTF_CloseFont(f.second);
    fonts.clear();
}

void Manager::reloadFonts() {
    clearFonts();
    loadFonts();
}

/* ----- TEXTURE MANAGER ----- */
// drawing procedures does not modify the color of the renderer : it always put it back to whatever it previously were

void Manager::Draw(SDL_Texture* text, const SDL_Rect* src, const SDL_Rect* dest, const SDL_RendererFlip flip) {
    if (!text) return;
    SDL_RenderCopyEx(Window::renderer, text, src, dest, 0, NULL, flip);
}

void Manager::DrawRect(const SDL_Rect* rect, const SDL_Color& color) {
    const SDL_Color t = SetRenderDrawColor(color);
    
    SDL_RenderDrawRect(Window::renderer, rect);

    SetRenderDrawColor(t);
}

void Manager::DrawFilledRect(const SDL_Rect* rect, const SDL_Color& color) {
    const SDL_Color t = SetRenderDrawColor(color);
    
    SDL_RenderFillRect(Window::renderer, rect);

    SetRenderDrawColor(t);
}

// centered variable isn't used because this is an early version of the function and i didn't found usefull to use the complete one
SDL_Texture* Manager::GenerateText(const std::string& text, const std::string& font, const SDL_Color& color, const int length, const bool centered){
    TTF_Font* f = Window::manager->getFont(font);

    if (!f) return nullptr;

    SDL_Surface* tmpSurface = TTF_RenderUTF8_Blended_Wrapped(f, text.c_str(), color, length);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Window::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return texture;
}

/* ----- WINDOW STATES MANAGER ----- */

void Manager::addWindowState(const WindowState::ID id, WindowState* ws) {
    windowStates.emplace(id, ws);
    windowStates[id]->init();
}
    
void Manager::addAndUseWindowState(const WindowState::ID id, WindowState* ws) {
    addWindowState(id, ws);
    setCurrentWindowState(id);
}

void Manager::removeWindowState(const WindowState::ID id) {
    if (windowStates.count(id) == 0)
        return;
    
    windowStates[id]->clean();
    windowStates.erase(id);
}

void Manager::setCurrentWindowState(const WindowState::ID id) {
    previousWindowState = currentWindowState;
    currentWindowState = id;
}

void Manager::updateCurrentState() {
    windowStates[currentWindowState]->update();
}

void Manager::renderCurrentState() {
    windowStates[currentWindowState]->render();
}

void Manager::clearWindowStates() {
    for (std::pair<const WindowState::ID, WindowState*> ws : windowStates)
        ws.second->clean();
    windowStates.clear();

    previousWindowState = WindowState::ID::UNKNOWN;
    currentWindowState = WindowState::ID::UNKNOWN;
}

WindowState* Manager::getState(const WindowState::ID id) {
    if (windowStates.count(id) == 0)
        return nullptr;
    return windowStates[id];
}

WindowState* Manager::getCurrentState() {
    return windowStates[currentWindowState];
} 

WindowState::ID Manager::getCurrentWindowStateID() {
    return currentWindowState;
}
