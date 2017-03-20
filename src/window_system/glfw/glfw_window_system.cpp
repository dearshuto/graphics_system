//
//  glfw_window_system.cpp
//  OpenGL
//
//  Created by Shuto on 2017/03/17.
//
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glfw_window.hpp"
#include "glfw_window_system.hpp"

bool fj::GLFWWindowSystem::initialize()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    return (glfwInit() == GLFW_TRUE);
}

std::unique_ptr<fj::Window> fj::GLFWWindowSystem::generateWindow(const fj::WindowInfo &info)const
{
    return std::make_unique<fj::GLFWWindow>(info);
}

void fj::GLFWWindowSystem::waitEvent()const
{
    glfwPollEvents();
}

void fj::GLFWWindowSystem::terminate()
{
    glfwTerminate();
}
