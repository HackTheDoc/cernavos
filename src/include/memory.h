#pragma once

#include "memoryItems.h"

namespace memory {
    /* ----- CONFIG ----- */

    void saveConfig();

    item::Config loadConfig();

}; // namespace memory