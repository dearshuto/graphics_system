//
//  glfw_window_builder.cpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/09.
//
//
#include <GL/glew.h>
#include "window_system/window_container.hpp"
#include "glfw_window_system.hpp"
#include "glfw_window_container.hpp"
#include "glfw_window_toolkit_builder.hpp"

std::unique_ptr<fj::WindowSystem> fj::GLFWWindowToolkitBuilder::createWindowSystem()const
{
    return std::make_unique<fj::GLFWWindowSystem>();
}

bool fj::GLFWWindowToolkitBuilder::initializeSystemExtension()
{
    glewExperimental = GL_TRUE;
    return (glewInit() == GLEW_OK);
}

std::unique_ptr<fj::WindowContainer> fj::GLFWWindowToolkitBuilder::createWindowContainer()const
{
    return std::make_unique<fj::GLFWWindowContainer>();
}
