#include <vector>
#include <iostream>
#include <filesystem>
#include "DataLoader.h"

namespace Core_NS {

    std::map<std::string, Texture*> DataLoader::_loadedTextures = std::map<std::string, Texture*>();

    unsigned char *DataLoader::get_texture2d(std::string textureName) {
        return DataLoader::_loadedTextures[textureName]->get_data();
    }

    void DataLoader::load_texture2ds(const char *texturesDirectory) {
        namespace fs = std::filesystem;
        int width, height, nrChannels;

        for (const auto & entry : fs::directory_iterator(texturesDirectory)) {
            std::string pathString = entry.path().string();
            DataLoader::_loadedTextures[pathString] = new Texture(pathString);
        }
    }

} // Core_NS