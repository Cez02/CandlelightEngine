#ifndef CANDLELIGHTENGINE_APPLICATION_H
#define CANDLELIGHTENGINE_APPLICATION_H

#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include "core/io_processing/IOProcessor.h"
#include "core/rendering/Renderer.h"

namespace Core_NS {
    class Application {
    private:
        GLFWwindow* window;
        const int WINDOW_WIDTH  = 1024;
        const int WINDOW_HEIGHT = 768;

        IOProcessor *ioprocessor;

        Renderer *renderer;

        static void cleanup();

    public:
        int init(int argc, char **argv);
        int loop();
    };

} // Core_NS

#endif //CANDLELIGHTENGINE_APPLICATION_H
