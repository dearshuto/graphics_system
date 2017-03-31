//
//  window_manager.cpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/09.
//
//

#include "window_system.hpp"
#include "window_manager.hpp"

bool fj::WindowManager::initialize(const fj::WindowInfo& windowInfo)
{
    m_window = fj::WindowSystem::GetInstance()->generateWindow(windowInfo);
    
    setup();
    
    return (m_window != nullptr);
}

void fj::WindowManager::mainloop()
{
    while (shouldUpdate())
    {
        pollEvent();
        
        render();
        
        swapBuffers();
    }
}

void fj::WindowManager::terminate()
{
    fj::WindowSystem::GetInstance()->terminate();
}

bool fj::WindowManager::shouldUpdate()const
{
    return getWindow().shouldUpdate();
}

void fj::WindowManager::pollEvent()
{
    fj::WindowSystem::GetInstance()->pollEvent();
}

void fj::WindowManager::swapBuffers()const
{
    getWindow().swapBuffers();
}

const fj::Window& fj::WindowManager::getWindow()const
{
    return *m_window;
}

fj::Window*const fj::WindowManager::getWindowPtr()
{
    return m_window.get();
}
