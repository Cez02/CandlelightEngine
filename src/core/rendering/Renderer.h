#ifndef CANDLELIGHTENGINE_RENDERER_H
#define CANDLELIGHTENGINE_RENDERER_H

#include <glad/glad.h>
#include "GLFW/glfw3.h"

namespace Core_NS {

    class Renderer {
    private:
        GLFWwindow *window;

        unsigned int VBO, VAO;
        unsigned int shaderProgram;

    public:
        explicit Renderer(GLFWwindow *window);
        void render_frame();
        void cleanup();
    };

} // Core_NS

#endif //CANDLELIGHTENGINE_RENDERER_H
