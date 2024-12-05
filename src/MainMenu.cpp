#include "include/WindowStates/MainMenu.h"

#include "include/Application.h"
#include "include/Window.h"

MainMenu::MainMenu() {}

MainMenu::~MainMenu() {}

void MainMenu::init() {
    /* ----- LABELS ----- */

    lbl_title = new UILabel(Application::TITLE, "h1", hue::font);
    lbl_title->place(8, 0);

    lbl_version = new UILabel(Application::VERSION, "default", hue::font);
    lbl_version->place(
        Window::screen.w - lbl_version->width() - 8,
        8
    );

    /* ----- BUTTONs ----- */

    const int offsetY = (Window::screen.h + lbl_title->height()) / 2;

    btn_options = new UIButton("Options", Event::ID::OPEN_OPTIONS, "h3", hue::font, UIButton::Type::RIGHT_CURSOR);
    btn_options->place(
        16,
        offsetY + 8
    );

    btn_options = new UIButton("Options", Event::ID::OPEN_OPTIONS, "h3", hue::font, UIButton::Type::RIGHT_CURSOR);
    btn_options->place(
        16,
        offsetY - btn_options->height() - 8
    );

    btn_play = new UIButton("Play", Event::ID::OPEN_GAME, "h3", hue::font, UIButton::Type::RIGHT_CURSOR);
    btn_play->place(
        16,
        offsetY - btn_options->height() - btn_play->height() - 24
    );

    btn_credits = new UIButton("Credits", Event::ID::OPEN_CREDITS, "h3", hue::font, UIButton::Type::RIGHT_CURSOR);
    btn_credits->place(
        16,
        offsetY + 8
    );

    btn_quit = new UIButton("Quit", Event::ID::QUIT, "h3", hue::font, UIButton::Type::RIGHT_CURSOR);
    btn_quit->place(
        16,
        offsetY + btn_credits->height() + 24
    );
}

void MainMenu::update() {
    btn_play->update();
    btn_options->update();
    btn_credits->update();
    btn_quit->update();
}

void MainMenu::render() {
    Manager::DrawFilledRect(&Window::screen, hue::background);
    
    btn_play->draw();
    btn_options->draw();
    btn_credits->draw();
    btn_quit->draw();

    lbl_title->draw();
    lbl_version->draw();
}

void MainMenu::clean() {
    btn_play->destroy();
    btn_options->destroy();
    btn_credits->destroy();
    btn_quit->destroy();

    lbl_title->destroy();
    lbl_version->destroy();
}
