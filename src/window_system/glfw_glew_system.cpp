//
//  glfw_glew_system.cpp
//  OpenGL
//
//  Created by Shuto on 2017/03/31.
//
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glfw/glfw_window.hpp"
#include "glfw_glew_system.hpp"

GLdouble fj::GLFWGLEWSystem::getTime()const
{
    return glfwGetTime();
}

void fj::GLFWGLEWSystem::genVertexArrays(GLsizei n, GLuint *arrays)const
{
    glGenVertexArrays(n, arrays);
}

void fj::GLFWGLEWSystem::deleteVertexArrays(GLsizei n, GLuint *arrays)const
{
    glDeleteVertexArrays(n, arrays);
}

void fj::GLFWGLEWSystem::bindVertexArray(GLuint array)const
{
    glBindVertexArray(array);
}

std::unique_ptr<fj::Window> fj::GLFWGLEWSystem::generateWindow(const fj::WindowInfo &info)const
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    
    GLFWwindow*const window = glfwCreateWindow(info.Width, info.Height, "TITLE", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    
    glewExperimental = GL_TRUE;
    glewInit();
    
    return std::make_unique<fj::GLFWWindow>(window);
}

void fj::GLFWGLEWSystem::pollEvent()const
{
    glfwPollEvents();
}

void fj::GLFWGLEWSystem::terminate()
{
    glfwTerminate();
}
