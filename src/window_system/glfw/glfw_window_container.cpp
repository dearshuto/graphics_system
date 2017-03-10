//
//  glfw_window_container.cpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/10.
//
//

#include "window_system/window.hpp"
#include "glfw_window_container.hpp"

//---- Iterator ----

fj::GLFWWindowContainer::Iterator::Iterator(fj::GLFWWindowContainer*const parent)
: m_parent(parent)
{
    reset();
}

void fj::GLFWWindowContainer::Iterator::reset()
{
    m_now = std::begin(m_parent->m_windows);
}

void fj::GLFWWindowContainer::Iterator::next()
{
    ++m_now;
}

bool fj::GLFWWindowContainer::Iterator::isDone()const
{
    return m_now == std::end(m_parent->m_windows);
}

const fj::Window& fj::GLFWWindowContainer::Iterator::getCurrentItem()const
{
    return *(*m_now);
}

fj::Window*const fj::GLFWWindowContainer::Iterator::getCurrentItemPtr()
{
    return (*m_now).get();
}



//---- GLFWWindowContainer

void fj::GLFWWindowContainer::addWindow(std::unique_ptr<fj::Window> window)
{
    auto pointer = window.release();
    m_windows.emplace_back(static_cast<fj::GLFWWindow*>(pointer));
}

std::unique_ptr<fj::Iterator<fj::Window>> fj::GLFWWindowContainer::iterator()
{
    return std::make_unique<fj::GLFWWindowContainer::Iterator>(this);
}
