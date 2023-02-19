#ifndef CANDLELIGHTENGINE_SHADER_H
#define CANDLELIGHTENGINE_SHADER_H

#include <iostream>

namespace Core_NS {

    class Shader {
    public:
        // the program ID
        unsigned int ID;

        // constructor reads and builds the shader
        Shader(std::string vertexPath, std::string fragmentPath);
        ~Shader();
        // use/activate the shader
        void use();
        // utility uniform functions
        void setBool(const std::string &name, bool value) const;
        void setInt(const std::string &name, int value) const;
        void setFloat(const std::string &name, float value) const;
    };

} // Core_NS

#endif //CANDLELIGHTENGINE_SHADER_H
