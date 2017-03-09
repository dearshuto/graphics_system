//
//  glfw_window_builder.cpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/09.
//
//

#include "window_system/window_container.hpp"
#include "window_system/window_generator.hpp"
#include "glfw_window_builder.hpp"

std::unique_ptr<fj::WindowGenerator> fj::GLFWWindowBuilder::createWindowGenerator()const
{
    return nullptr;
}

std::unique_ptr<fj::WindowContainer> fj::GLFWWindowBuilder::createWindowContainer()const
{
    return nullptr;
}
