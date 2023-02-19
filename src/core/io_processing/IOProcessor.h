#ifndef CANDLELIGHTENGINE_IOPROCESSOR_H
#define CANDLELIGHTENGINE_IOPROCESSOR_H

#include "GLFW/glfw3.h"

namespace Core_NS {

    class IOProcessor {
    private:
        GLFWwindow *window;

    public:
        explicit IOProcessor(GLFWwindow *window);

        void process_input();
    };

} // Core_NS

#endif //CANDLELIGHTENGINE_IOPROCESSOR_H
