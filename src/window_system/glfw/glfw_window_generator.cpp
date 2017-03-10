//
//  glfw_window_generator.cpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/10.
//
//

#include <GLFW/glfw3.h>
#include "window_system/window.hpp"
#include "glfw_window.hpp"
#include "glfw_window_generator.hpp"

bool fj::GLFWWindowGenerator::initialize()
{
    bool result = true;
    
    result &= (glfwInit() == GLFW_TRUE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    return result;
}

void fj::GLFWWindowGenerator::terminate()
{
    glfwTerminate();
}

std::unique_ptr<fj::Window> fj::GLFWWindowGenerator::generateWindow(const fj::WindowInfo& windowInfo)const
{
    return std::make_unique<fj::GLFWWindow>(windowInfo);
}
