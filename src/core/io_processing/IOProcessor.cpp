#include "IOProcessor.h"

namespace Core_NS {

    IOProcessor::IOProcessor(GLFWwindow *window)
        : window(window) { }

    void IOProcessor::process_input() {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }
}