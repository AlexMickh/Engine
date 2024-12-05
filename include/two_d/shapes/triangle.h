#pragma once

#include <cmath>
#include "shape.h"

namespace two_d
{
    class Triangle : public Shape
    {
    private:
        GLuint shaderProgram;
        GLuint vao;
        GLfloat points[9] = {0.0f};
    
        void convertVector(two_d::Vector2 position, GLuint a);
    public:
        Triangle(const char *vertexShader, const char *fragmentShader, two_d::Vector2 position, GLfloat a, GLfloat colors[]);
        GLuint GetShaderProgram() override;
        GLuint GetVao() override;
    };
}