#include <iostream>
#include <cstring>
#include "glad.h"
#include <GLFW/glfw3.h>
#include "../include/two_d/shapes/shape.h"
#include "../include/two_d/shapes/triangle.h"
#include "../include/utils/readShader.h"

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

    std::string path(std::getenv("FILE")); // here we need environment variable

    const std::string shader1 = utils::ReadShader(path + "/modules/shaders/triangle.vert");
    const GLchar *vertexShader = shader1.c_str();

    const std::string shader2 = utils::ReadShader(path + "/modules/shaders/triangle.frag");
    const GLchar *fragmentShader = shader2.c_str();

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
