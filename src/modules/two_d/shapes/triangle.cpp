#include "../../../../include/two_d/shapes/triangle.h"
#include <iostream>

void two_d::Triangle::convertVector(two_d::Vector2 position, GLuint a)
{
    GLfloat center = (a * sqrt(a)) / 2 / 10;

    position.x /= 100;
    position.y /= 100;
    
    this->points[0] = position.x;
    this->points[1] = position.y + center;
    this->points[2] = 0.0f;
    this->points[3] = position.x + center;
    this->points[4] = position.y - center;
    this->points[5] = 0.0f;
    this->points[6] = position.x - center;
    this->points[7] = position.y - center;
    this->points[8] = 0.0f;
}

two_d::Triangle::Triangle(const char *vertexShader, const char *fragmentShader, two_d::Vector2 position, GLfloat a, GLfloat colors[])
{
    this->convertVector(position, a);

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
    glBufferData(GL_ARRAY_BUFFER, 36, this->points, GL_STATIC_DRAW); // here we need sizeof points

    GLuint colors_vbo;
    glGenBuffers(1, &colors_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, colors_vbo);
    glBufferData(GL_ARRAY_BUFFER, 36, colors, GL_STATIC_DRAW); // here we need sizeof colors

    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 0, nullptr);

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