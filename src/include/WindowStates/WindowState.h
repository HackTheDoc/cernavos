#pragma once

class WindowState {
public:
    enum ID {
        UNKNOWN,

        MAIN,
    };

    WindowState() {}
    ~WindowState() {}

    virtual void init() {}
    virtual void update() {}
    virtual void render() {}
    virtual void clean() {}

    virtual void reload() {} 
};
