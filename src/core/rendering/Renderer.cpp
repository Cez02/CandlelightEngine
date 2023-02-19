#include "Renderer.h"
#include "Shader.h"
#include "Candlelight/Candlellight.h"
#include <glm/glm.hpp>
#include <iostream>
#include <filesystem>

namespace Core_NS {

    Renderer::Renderer(GLFWwindow *window)
        : window(window) {

        std::cout << "Creating shader" << std::endl;
        shader = new Shader(
                std::filesystem::current_path().string() + REN_STD_VERTEX_SHADER,
                std::filesystem::current_path().string() + REN_STD_FRAGMENT_SHADER); // you can name your shader files however you like
        std::cout << "Shader created" << std::endl;

        float vertices[] = {
                // positions         // colors
                0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
                -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
                0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top
        };

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        // color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);


    }

    void Renderer::render_frame() {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader->use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

    }

    void Renderer::cleanup() {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        delete shader;
    }
} // Core_NS