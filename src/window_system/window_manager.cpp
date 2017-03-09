//
//  window_manager.cpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/09.
//
//

#include "window_manager.hpp"

fj::WindowManager::WindowManager(std::unique_ptr<fj::WindowBuilder> windowBuilder)
{
    m_windowContainer = windowBuilder->createWindowContainer();
    m_windowGenerator = windowBuilder->createWindowGenerator();
}

bool fj::WindowManager::initialize()
{
    bool result = true;
    
    result &= getWindowGeneratorPtr()->initialize();
    
    return result;
}

void fj::WindowManager::mainloop()
{
    
}

void fj::WindowManager::terminate()
{
    getWindowGeneratorPtr()->terminate();
}

const fj::WindowContainer& fj::WindowManager::getWindowContainer()const
{
    return *m_windowContainer;
}

fj::WindowContainer*const fj::WindowManager::getWindowContainerPtr()
{
    return m_windowContainer.get();
}

const fj::WindowGenerator& fj::WindowManager::getWindowGenerator()const
{
    return *m_windowGenerator;
}

fj::WindowGenerator*const fj::WindowManager::getWindowGeneratorPtr()
{
    return m_windowGenerator.get();
}
