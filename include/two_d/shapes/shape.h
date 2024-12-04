#pragma once
#include "../../../src/glad.h"
#include <GLFW/glfw3.h>

namespace two_d
{
    class Shape
    {
    public:
        virtual GLuint GetShaderProgram() = 0;
        virtual GLuint GetVao() = 0;
    };
}