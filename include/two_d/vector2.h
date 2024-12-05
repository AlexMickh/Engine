#pragma once

#include <GLFW/glfw3.h>

namespace two_d
{
    struct Vector2
    {
    public:
        GLfloat x;
        GLfloat y;

        Vector2();
        Vector2(GLfloat x, GLfloat y);
    };
    
}