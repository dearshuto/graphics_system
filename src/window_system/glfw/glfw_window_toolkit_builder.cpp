//
//  glfw_window_builder.cpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/09.
//
//

#include "window_system/window_container.hpp"
#include "glfw_window_container.hpp"
#include "glfw_window_generator.hpp"
#include "glfw_window_toolkit_builder.hpp"

std::unique_ptr<fj::WindowGenerator> fj::GLFWWindowToolkitBuilder::createWindowGenerator()const
{
    return std::make_unique<fj::GLFWWindowGenerator>();
}

std::unique_ptr<fj::WindowContainer> fj::GLFWWindowToolkitBuilder::createWindowContainer()const
{
    return std::make_unique<fj::GLFWWindowContainer>();
}
