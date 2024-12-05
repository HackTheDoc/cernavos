#include "include/serialization.h"

#include <fstream>

namespace serialize {
    
    template <typename T>
    void var(std::ofstream& outfile, const T& var) {
        outfile.write(reinterpret_cast<const char*>(&var), sizeof(T));
    }

    void config(const memory::item::Config& config) {
        std::ofstream outfile("config", std::ios::binary);

        var(outfile, config.autosave);

        var(outfile, config.fullscreen);

        outfile.close();
    }
    
} // namespace serialize

namespace deserialize {

    template <typename T>
    void var(std::ifstream& infile, T& var) {
        infile.read(reinterpret_cast<char*>(&var), sizeof(T));
    }

    memory::item::Config config() {
        memory::item::Config citem;

        std::ifstream infile("config", std::ios::binary);

        var(infile, citem.autosave);

        var(infile, citem.fullscreen);

        infile.close();

        return citem;
    }
    
} // namespace deserialize
