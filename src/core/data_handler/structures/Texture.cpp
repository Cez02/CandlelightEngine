#include "Texture.h"
#include <glad/glad.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace Core_NS {
    Texture::Texture(const std::filesystem::directory_entry &textureDirent) {
        // load data
        stbi_set_flip_vertically_on_load(true);
        _data = stbi_load(textureDirent.path().string().c_str(), &_width, &_height, &_nrChannels, 0);

        // bind in opengl
        glGenTextures(1, &_textureID);
        glBindTexture(GL_TEXTURE_2D, _textureID);

        // texture settings
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, _data);
        glGenerateMipmap(GL_TEXTURE_2D);

        if(!_data){
            std::cerr << "Failed to load texture " << textureDirent.path().filename().string() << "\n";
            exit(-1);
        }

        stbi_image_free(_data);
    }

    unsigned int Texture::get_id() {
        return _textureID;
    }
}