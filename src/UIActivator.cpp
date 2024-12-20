#include "include/UI/UIActivator.h"

#include "include/memory.h"
#include "include/Window.h"
#include "include/Application.h"

UIActivator::UIActivator(const std::string& t, bool* v) {
    tag = t;
    var = v;

    title = new UILabel(tag, "default bold", hue::font);

    value = new UILabel(vstring[*var], "default", hue::font);

    rect.w = title->width() + value->width() + 4 * (Window::fullscreen + 1);
    rect.h = std::max(title->height(), value->height());

    place(0, 0);
}

UIActivator::~UIActivator() {}

void UIActivator::draw() {
    title->draw();
    value->draw();
}

void UIActivator::update() {
    SDL_Point m;
    SDL_GetMouseState(&m.x, &m.y);

    if (SDL_PointInRect(&m, &rect) && Window::event.mouseClickLeft()) {
        *var = !*var;

        value->setText(vstring[*var], "default", hue::font);
        value->place(
            title->x() + title->width() + 4 * (Window::fullscreen + 1),
            rect.y + (rect.h - value->height()) / 2
        );

        // sadly i don't think there is a better way than forcing the window reload if we are modifying the fullscreen status of the window
        if (var == &Window::fullscreen)
            Application::ReloadWindow();

        memory::saveConfig();
    }
}

void UIActivator::destroy() {
    title->destroy();
    value->destroy();
}

void UIActivator::place(const int x, const int y) {
    rect.x = x;
    rect.y = y;

    title->place(
        x,
        y + (rect.h - title->height()) / 2
    );

    value->place(
        title->x() + title->width() + 4 * (Window::fullscreen + 1),
        y + (rect.h - value->height()) / 2
    );
}

void UIActivator::reload() {
    title->setText(tag, "default bold", hue::font);

    value->setText(vstring[*var], "default", hue::font);

    rect.w = title->width() + value->width() + 4 * (Window::fullscreen + 1);
    rect.h = std::max(title->height(), value->height());
}
