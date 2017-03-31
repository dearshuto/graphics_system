//
//  window_system.cpp
//  OpenGL
//
//  Created by Shuto on 2017/04/01.
//
//

#include "glfw_glew_system.hpp"
#include "window_system.hpp"

fj::WindowSystem* fj::WindowSystem::GetInstance()
{
    static fj::GLFWGLEWSystem windowSystem;
    return &windowSystem;
}
