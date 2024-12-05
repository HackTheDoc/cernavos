#pragma once

#include "memoryItems.h"

/// @brief contain all functions, procedures and structures related to memory manipulation within the application (ex: for saves)
namespace memory {
    /* ----- CONFIG ----- */

    void saveConfig();

    item::Config loadConfig();

}; // namespace memory