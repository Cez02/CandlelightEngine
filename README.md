# Candlelight Engine

## Introduction

As a little passion project of mine, the Candlelight Engine will serve me the purpose of studying game engine development and architecture. Additionally, it'll help me understand 3D graphics rendering and other aspects of low-level game development.

## Installation

This project requires several dependencies:
- GLFW3
- GLAD
- GLM
- STB_IMAGE

For GLFW3 I of course advise downloading the source code and compiling the library yourself. Once you do that, you need to put the GLFW include directory in the include directory in the project. The .lib or .a library file should go into the lib directory.
For Glad and stb_image you put the generated source files in the thirdparty directory and the header into the include directory.
Since GLM is a header-only directory you place it into the include directory along with KHR.

The cmake directory has module scripts inside to help with finding GLM and GLFW3 - helps to keep the CMakeLists.txt file concise and readable.