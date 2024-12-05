#pragma once
#include "../../../src/glad.h"
#include <GLFW/glfw3.h>
#include "../vector2.h"

namespace two_d
{
    class Shape
    {
    protected:
        virtual void convertVector(two_d::Vector2 position, GLuint a) = 0;
    public:
        virtual GLuint GetShaderProgram() = 0;
        virtual GLuint GetVao() = 0;
    };
}