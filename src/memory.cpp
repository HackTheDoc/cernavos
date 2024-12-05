#include "include/memory.h"
#include "include/serialization.h"

#include "include/Window.h"
#include "include/Game/Game.h"

namespace memory {

/* ----- CONFIG ----- */

void createConfig() {
    const item::Config config{
        .autosave = true,
        .fullscreen = false,
    };

    serialize::config(config);
}

void saveConfig() {
    item::Config config = loadConfig();

    config.autosave = Game::AutoSave;

    config.fullscreen = Window::fullscreen;

    serialize::config(config);
}

item::Config loadConfig() {
    if (!fs::exists("config")) createConfig();

    const item::Config config = deserialize::config();

    return config;
}

}; // namespace memory
