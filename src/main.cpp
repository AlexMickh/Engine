#include <iostream>
#include "glad.h"
#include <GLFW/glfw3.h>
#include "../include/two_d/shapes/shape.h"
#include "../include/two_d/shapes/triangle.h"

GLfloat points[] = {
    0.0f, 0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f
};

GLfloat points2[] = {
    0.5f, 0.5f, 0.0f,
    0.0f, -0.5f, 0.0f,
    -0.5f, 0.5f, 0.0f
};

GLfloat colors[] = {
    1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f
};

const char *vertexShader =
"#version 330\n"
"layout(location = 0) in vec3 vertex_position;"
"layout(location = 1) in vec3 vertex_color;"
"out vec3 color;"
"void main() {"
"   color = vertex_color;"
"   gl_Position = vec4(vertex_position, 1.0);"
"}";

const char *fragmentShader =
"#version 330\n"
"in vec3 color;"
"out vec4 frag_color;"
"void main() {"
"   frag_color = vec4(color, 1.0);"
"}";

int main()
{
    GLFWwindow *window;

    if (!glfwInit()) 
    {
        std::exit(1);
    }

    window = glfwCreateWindow(1280, 720, "Engine", NULL, NULL);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Couldn't load OpenGL" << std::endl;
        glfwTerminate();
        std::exit(1);
    }

    glClearColor(0.25f, 0.5f, 0.75f, 1.0f);

    two_d::Shape *shape = new two_d::Triangle(vertexShader, fragmentShader, points, colors);
    two_d::Shape *triangleShape = new two_d::Triangle(vertexShader, fragmentShader, points2, colors);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shape->GetShaderProgram());
        glBindVertexArray(shape->GetVao());
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(triangleShape->GetShaderProgram());
        glBindVertexArray(triangleShape->GetVao());
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
    }

    delete shape;
    delete triangleShape;

    glfwTerminate();

    return 0;
}
