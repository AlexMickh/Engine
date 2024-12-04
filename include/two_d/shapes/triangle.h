#pragma once
#include "shape.h"

namespace two_d
{
    class Triangle : public Shape
    {
    private:
        GLuint shaderProgram;
        GLuint vao;
    public:
        Triangle(const char *vertexShader, const char *fragmentShader, GLfloat points[], GLfloat colors[]);
        GLuint GetShaderProgram() override;
        GLuint GetVao() override;
    };
}