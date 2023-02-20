#ifndef CANDLELIGHTENGINE_TEXTURE_H
#define CANDLELIGHTENGINE_TEXTURE_H

#include <string>
#include <filesystem>

namespace Core_NS {
    class Texture {
    private:
        int _width,
            _height,
            _nrChannels;

        unsigned int _textureID;

        unsigned char * _data;

    public:
        Texture(const std::filesystem::directory_entry &textureDirent);

        unsigned int get_id();
    };
}


#endif //CANDLELIGHTENGINE_TEXTURE_H
