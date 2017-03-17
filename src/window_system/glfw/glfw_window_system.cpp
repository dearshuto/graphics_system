//
//  glfw_window_system.cpp
//  OpenGL
//
//  Created by Shuto on 2017/03/17.
//
//

#include <GLFW/glfw3.h>
#include "glfw_window.hpp"
#include "glfw_window_system.hpp"

bool fj::GLFWWindowSystem::initialize()
{
    return (glfwInit() == GLFW_TRUE);
}

std::unique_ptr<fj::Window> fj::GLFWWindowSystem::generateWindow(const fj::WindowInfo &info)const
{
    return std::make_unique<fj::GLFWWindow>(info);
}

void fj::GLFWWindowSystem::terminate()
{
    glfwTerminate();
}
