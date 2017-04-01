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

const fj::Window& fj::WindowSystem::getWindow()const
{
    return *m_window;
}

fj::Window*const fj::WindowSystem::getWindowPtr()
{
    return m_window.get();
}

void fj::WindowSystem::setWindow(std::unique_ptr<fj::Window> window)
{
    m_window = std::move(window);
}
