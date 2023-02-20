#include "Application.h"
#include "core/data_handler/DataLoader.h"
#include <iostream>

namespace Core_NS {

    void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    void Application::cleanup() {
        glfwTerminate();
    }

    int Application::init(int argc, char **argv) {
        /* Initialize the library */
        if (!glfwInit())
            return -1;

        /* Create a windowed mode window and its OpenGL context */
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hello Modern GL!", nullptr, nullptr);

        if (!window) {
            glfwTerminate();
            return -1;
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);
        glfwSetWindowSizeCallback(window, framebuffer_size_callback);

        /* Initialize glad */
        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return -1;
        }

        std::cout << "Window created" << std::endl;

        DataLoader::load_texture2ds("data/textures");

        ioprocessor = new IOProcessor(window);
        renderer = new Renderer(window);

        std::cout << "IOProcessor and renderer created" << std::endl;


        return 0;
    }

    int Application::loop(){
        while(!glfwWindowShouldClose(window)){

            // input
            ioprocessor->process_input();

            // rendering
            renderer->render_frame();

            // buffer swapping
            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        Application::cleanup();
        return 0;
    }

} // Core_NS