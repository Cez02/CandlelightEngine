#include "Renderer.h"
#include "Shader.h"
#include "../data_handler/DataLoader.h"
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
                // positions                    // colors                       // texture coords
                0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
                0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
                -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
                -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left
        };

        unsigned int indices[] = {
                0, 1, 3, // first triangle
                1, 2, 3  // second triangle
        };

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        // color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        // texture coord attribute
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);


        shader->setInt("texture1", DataLoader::get_texture2d("6d3.jpg"));
    }

    void Renderer::render_frame() {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // bind Texture
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, DataLoader::get_texture2d("6d3.jpg"));

        shader->use();
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    }

    void Renderer::cleanup() {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        delete shader;
    }
} // Core_NS