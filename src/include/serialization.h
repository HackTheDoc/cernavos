#pragma once

#include "memoryItems.h"

#include <filesystem>

namespace fs = std::filesystem;

/// @brief convert memory items to binary and save it in the proper file
namespace serialize {

    void config(const memory::item::Config& config);
    
} // namespace serialize

/// @brief convert binary data to memory items of the application
namespace deserialize {

    memory::item::Config config();
    
} // namespace deserialize
