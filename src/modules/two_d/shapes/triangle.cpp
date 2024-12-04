#include "../../../../include/two_d/shapes/triangle.h"

two_d::Triangle::Triangle(const char *vertexShader, const char *fragmentShader, GLfloat points[], GLfloat colors[])
{
    GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderID, 1, &vertexShader, nullptr);
    glCompileShader(vertexShaderID);

    GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderID, 1, &fragmentShader, nullptr);
    glCompileShader(fragmentShaderID);

    this->shaderProgram = glCreateProgram();
    glAttachShader(this->shaderProgram, vertexShaderID);
    glAttachShader(this->shaderProgram, fragmentShaderID);
    glLinkProgram(this->shaderProgram);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);

    GLuint points_vbo;
    glGenBuffers(1, &points_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
    glBufferData(GL_ARRAY_BUFFER, 36, points, GL_STATIC_DRAW); // here we need sizeof points

    GLuint colors_vbo;
    glGenBuffers(1, &colors_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, colors_vbo);
    glBufferData(GL_ARRAY_BUFFER, 36, colors, GL_STATIC_DRAW); // here we need sizeof colors

    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colors_vbo);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
}

GLuint two_d::Triangle::GetShaderProgram()
{
    return this->shaderProgram;
}

GLuint two_d::Triangle::GetVao()
{
    return this->vao;
}