#include "include/WindowStates/OptionsMenu.h"

#include "include/Window.h"
#include "include/Game/Game.h"

OptionsMenu::OptionsMenu() {}

OptionsMenu::~OptionsMenu() {}

void OptionsMenu::createGeneralPage() {
    UIActivator* fa = new UIActivator("Fullscreen:", &Window::fullscreen);
    fa->place(
        (Window::screen.w - fa->width()) / 2,
        border.y + 32 * (Window::fullscreen + 1)
    );

    UIActivator* sma = new UIActivator("Save Mode:", &Game::AutoSave);
    sma->place(
        (Window::screen.w - sma->width()) / 2,
        fa->y() + fa->height() + 32 * (Window::fullscreen + 1)
    );

    page[GENERAL] = {
        {"fa", fa},
        {"sma", sma},
    };
}

void OptionsMenu::reloadGeneralPage() {
    UIActivator* fa = static_cast<UIActivator*>(page[GENERAL]["fa"]);
    fa->reload();
    fa->place(
        (Window::screen.w - fa->width()) / 2,
        border.y + 32 * (Window::fullscreen + 1)
    );

    UIActivator* sma = static_cast<UIActivator*>(page[GENERAL]["sma"]);
    sma->reload();
    sma->place(
        (Window::screen.w - sma->width()) / 2,
        fa->y() + fa->height() + 32 * (Window::fullscreen + 1)
    );
}

void OptionsMenu::createControlsPage() {

}

void OptionsMenu::reloadControlsPage() {

}

void OptionsMenu::init() {
    btn_generalSection = new UIButton("GENERAL", Event::ID::OPEN_GENERAL_SETTINGS, "h3", hue::font);
    btn_generalSection->place(
        (Window::screen.w / 2 - btn_generalSection->width()) / 2,
        8 * (Window::fullscreen + 1)
    );

    btn_controlsSection = new UIButton("CONTROLS", Event::ID::OPEN_CONTROLS_SETTINGS, "h3", hue::font);
    btn_controlsSection->place(
        (3 * Window::screen.w / 2 - btn_controlsSection->width()) / 2,
        8 * (Window::fullscreen + 1)
    );

    btn_quit = new UIButton("X", Event::ID::OPEN_MAIN_MENU, "h3", hue::font);
    btn_quit->place(
        Window::screen.w - btn_quit->width() - 8 * (Window::fullscreen + 1),
        8 * (Window::fullscreen + 1)
    );

    border = {
        0,
        8 * (Window::fullscreen + 1) + std::max(btn_generalSection->height(), btn_controlsSection->height()),
        Window::screen.w,
        3 * (Window::fullscreen + 1)
    };

    createGeneralPage();
    createControlsPage();

    usePage(Page::GENERAL);
}

void OptionsMenu::update() {
    btn_generalSection->update();
    btn_controlsSection->update();
    btn_quit->update();

    for (const auto& elt : page[currentPage])
        elt.second->update();
}

void OptionsMenu::render() {
    Manager::DrawFilledRect(&Window::screen, hue::background);

    btn_generalSection->draw();
    btn_controlsSection->draw();
    btn_quit->draw();

    Manager::DrawFilledRect(&border, hue::border);

    for (const auto& elt : page[currentPage])
        elt.second->draw();
}

void OptionsMenu::clean() {
    btn_generalSection->destroy();
    btn_controlsSection->destroy();
    btn_quit->destroy();

    for (auto elt : page[GENERAL])
        elt.second->destroy();
    page[GENERAL].clear();
    
    for (auto elt : page[CONTROLS])
        elt.second->destroy();
    page[CONTROLS].clear();
}

void OptionsMenu::reload() {
    btn_generalSection->setText("GENERAL", "h3", hue::font);
    btn_generalSection->place(
        (Window::screen.w / 2 - btn_generalSection->width()) / 2,
        8 * (Window::fullscreen + 1)
    );

    btn_controlsSection->setText("CONTROLS", "h3", hue::font);
    btn_controlsSection->place(
        (3 * Window::screen.w / 2 - btn_controlsSection->width()) / 2,
        8 * (Window::fullscreen + 1)
    );

    btn_quit->setText("X", "h3", hue::font);
    btn_quit->place(
        Window::screen.w - btn_quit->width() - 8 * (Window::fullscreen + 1),
        8 * (Window::fullscreen + 1)
    );

    border = {
        0,
        8 * (Window::fullscreen + 1) + std::max(btn_generalSection->height(), btn_controlsSection->height()),
        Window::screen.w,
        3 * (Window::fullscreen + 1)
    };

    reloadGeneralPage();
    reloadControlsPage();
}

void OptionsMenu::usePage(const Page p) {
    currentPage = p;
}
