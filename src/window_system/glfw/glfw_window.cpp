//
//  glfw_window.cpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/10.
//
//

#include <GLFW/glfw3.h>
#include "glfw_window.hpp"

void clearWindow(GLFWwindow*const window)
{
    const float kR = 1.0f, kG = 1.0, kB = 1.0f, kA = 0.0f;
    glfwMakeContextCurrent(window);
    glClearColor(kR, kG, kB, kA);
    glClear(GL_COLOR_BUFFER_BIT);
}

void refleshWindowCallback(GLFWwindow* window)
{
    clearWindow(window);
}

fj::GLFWWindow::GLFWWindow(const fj::WindowInfo& info)
{
    m_window = glfwCreateWindow(info.Width, info.Height, "", nullptr, nullptr);
    glfwSetWindowRefreshCallback(m_window, refleshWindowCallback);
    glfwMakeContextCurrent(m_window);
}

bool fj::GLFWWindow::shouldUpdate()const
{
    return (glfwWindowShouldClose(m_window) == GLFW_FALSE);
}

void fj::GLFWWindow::clear()
{
    clearWindow(m_window);
}

void fj::GLFWWindow::swapBuffers()
{
    glfwSwapBuffers(m_window);
//    glfwWaitEvents();
}

void fj::GLFWWindow::terminate()
{
    glfwDestroyWindow(m_window);
}
