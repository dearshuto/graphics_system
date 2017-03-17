//
//  window_manager.cpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/09.
//
//

#include "glfw/glfw_window_toolkit_builder.hpp"
#include "utility/iterator.hpp"
#include "window_system.hpp"
#include "window_toolkit_builder.hpp"
#include "window_manager.hpp"

bool fj::WindowManager::initialize()
{
    bool result = true;
    
    auto windowBuilder = std::make_unique<fj::GLFWWindowToolkitBuilder>();
    m_windowSystem = windowBuilder->createWindowSystem();
    
    result &= m_windowSystem->initialize();
    generateWindow({640, 480});
    
    result &= windowBuilder->initializeSystemExtension();
    
    return result;
}

void fj::WindowManager::generateWindow(const fj::WindowInfo &info)
{
    m_mainWindow = getWindowSystem().generateWindow(info);
}

void fj::WindowManager::mainloop()
{
    while (m_mainWindow->shouldUpdate())
    {
        m_mainWindow->update();
    }
}

void fj::WindowManager::terminate()
{
    getWindowSystemPtr()->terminate();
}

const fj::WindowSystem& fj::WindowManager::getWindowSystem()const
{
    return *m_windowSystem;
}

fj::WindowSystem*const fj::WindowManager::getWindowSystemPtr()
{
    return m_windowSystem.get();
}
