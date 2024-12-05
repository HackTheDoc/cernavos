#pragma once

#include <map>
#include <vector>
#include <string>

#include "WindowState.h"

#include "../UI/UIElements.h"

class OptionsMenu : public WindowState {
public:
    enum Page {
        GENERAL,
        CONTROLS
    };

    OptionsMenu();
    ~OptionsMenu();

    void init() override;
    void update() override;
    void render() override;
    void clean() override;
    void reload() override;

    /// @brief change current page of options
    /// @param p 
    void usePage(const Page p);

private:
    UIButton* btn_quit;
    UIButton* btn_generalSection;
    UIButton* btn_controlsSection;

    SDL_Rect border;

    std::map<std::string, UIElement*> page[2];
    int currentPage;

    void createGeneralPage();
    void createControlsPage();

    void reloadGeneralPage();
    void reloadControlsPage();
};
