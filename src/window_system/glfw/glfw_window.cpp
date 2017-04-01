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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void refleshWindowCallback(GLFWwindow* window)
{
    clearWindow(window);
}

fj::GLFWWindow::GLFWWindow(GLFWwindow*const window)
: m_window(window)
{
    
}

bool fj::GLFWWindow::shouldUpdate()const
{
    return (glfwWindowShouldClose(m_window) == GLFW_FALSE);
}

void fj::GLFWWindow::swapBuffers()const
{
    glfwSwapBuffers(m_window);
}

void fj::GLFWWindow::terminate()
{
    glfwDestroyWindow(m_window);
}

GLFWwindow*const fj::GLFWWindow::getRawWindowPtr()
{
    return m_window;
}
