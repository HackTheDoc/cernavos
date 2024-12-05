#pragma once

#include "UIElement.h"
#include "UILabel.h"

class UIActivator : public UIElement {
public:
    /// @brief 
    /// @param t display name of the activator 
    /// @param v pointer to the variable to update
    UIActivator(const std::string& t, bool* v);
    ~UIActivator();

    void draw() override;
    void update() override;
    void destroy() override;

    /// @brief in pixels with (0,0) being the top left corner
    /// @param x 
    /// @param y 
    void place(const int x, const int y);

    void reload();

private:
    /// @brief to convert boolean to string
    const std::string vstring[2] = {"Off", "On"};

    UILabel* title;
    UILabel* value;

    std::string tag;
    bool* var;
};
