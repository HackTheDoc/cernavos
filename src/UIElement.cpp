#include "include/UI/UIElement.h"

UIElement::~UIElement() {}


void UIElement::draw() {}

void UIElement::update() {}

void UIElement::destroy() {}

void UIElement::place(const int x, const int y) {
    rect.x = x;
    rect.y = y;
}   

int UIElement::x() {
    return rect.x;
}  

int UIElement::y() {
    return rect.y;
}  

int UIElement::width() {
    return rect.w;
}  

int UIElement::height() {
    return rect.h;
}  
