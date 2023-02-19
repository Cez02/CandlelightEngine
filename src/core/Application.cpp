#include "Application.h"
#include <iostream>

namespace Core_NS {

    int Application::init(int argc, char **argv) {
        /* Initialize the library */
        if (!glfwInit())
            return -1;

        /* Create a windowed mode window and its OpenGL context */
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hello Modern GL!", nullptr, nullptr);

        if (!window)
        {
            glfwTerminate();
            return -1;
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);

        /* Initialize glad */
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return -1;
        }

        /* Set the viewport */
        glClearColor(0.6784f, 0.8f, 1.0f, 1.0f);
        glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

        glEnable(GL_DEPTH_TEST);

        return 0;
    }

    int Application::loop(){
        while(!glfwWindowShouldClose(window)){



        }
        return 0;
    }

} // Core_NS