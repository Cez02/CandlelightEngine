# Candlelight Engine

## Introduction

As a little passion project of mine, the Candlelight Engine will serve me the purpose of studying game engine development and architecture. Additionally, it'll help me understand 3D graphics rendering and other aspects of low-level game development.

## Installation

This project requires several dependencies:
- GLFW3
- GLAD
- GLM
- STB_IMAGE

For GLFW3 I of course advise downloading the source code and compiling the library yourself. If you have GLFW3 on your machine, CMake may find it, however that depends on the directory. If you do compile GLFW yourself, copy the .lib or .a file to the lib directory (create one if it doesn't exist).

The cmake directory has module scripts inside to help with finding GLM and GLFW3 - helps to keep the CMakeLists.txt file concise and readable.