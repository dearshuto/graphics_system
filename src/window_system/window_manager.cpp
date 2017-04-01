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
    fj::WindowSystem::GetInstance()->generateWindow(windowInfo);
    m_guiToolkit = fj::WindowSystem::GetInstance()->generateGUIToolkit();
    
    setup();
    
    return m_guiToolkit->initialize();
}

void fj::WindowManager::mainloop()
{
    while (shouldUpdate())
    {
        detectEvent();
        
        pollEvent();
        
        render();
        
        swapBuffers();
    }
}

void fj::WindowManager::terminate()
{
    getGUIToolkitPtr()->terminate();
    fj::WindowSystem::GetInstance()->terminate();
}

bool fj::WindowManager::shouldUpdate()const
{
    return getWindow().shouldUpdate();
}

void fj::WindowManager::detectEvent()
{
    fj::WindowSystem::GetInstance()->pollEvent();
    getGUIToolkitPtr()->pollEvent();
}

void fj::WindowManager::swapBuffers()const
{
    getGUIToolkit().redraw();
    getWindow().swapBuffers();
}

const fj::Window& fj::WindowManager::getWindow()const
{
    return fj::WindowSystem::GetInstance()->getWindow();
}

fj::Window*const fj::WindowManager::getWindowPtr()
{
    return fj::WindowSystem::GetInstance()->getWindowPtr();
}

const fj::GUIToolkit& fj::WindowManager::getGUIToolkit()const
{
    return *m_guiToolkit;
}

fj::GUIToolkit*const fj::WindowManager::getGUIToolkitPtr()
{
    return m_guiToolkit.get();
}
