#ifndef CANDLELIGHTENGINE_TEXTURE_H
#define CANDLELIGHTENGINE_TEXTURE_H

#include <string>

namespace Core_NS {
    class Texture {
    private:
        int _width,
            _height,
            _nrChannels;

        unsigned int _textureID;

        unsigned char * _data;

    public:
        Texture(std::string textureName);

        unsigned char *get_data();
    };
}


#endif //CANDLELIGHTENGINE_TEXTURE_H
