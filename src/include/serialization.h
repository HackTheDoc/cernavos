#pragma once

#include "memoryItems.h"

#include <filesystem>

namespace fs = std::filesystem;

namespace serialize {

    void config(const memory::item::Config& config);
    
} // namespace serialize

namespace deserialize {

    memory::item::Config config();
    
} // namespace deserialize
