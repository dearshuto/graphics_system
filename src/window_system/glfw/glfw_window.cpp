//
//  glfw_window.cpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/10.
//
//

#include <GLFW/glfw3.h>
#include "glfw_window.hpp"

void redrawWindow(GLFWwindow*const window)
{
    const float kR = 1.0f, kG = 1.0, kB = 1.0f, kA = 0.0f;
    glfwMakeContextCurrent(window);
    glClearColor(kR, kG, kB, kA);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
}

void refleshWindowCallback(GLFWwindow* window)
{
    redrawWindow(window);
}

fj::GLFWWindow::GLFWWindow(const fj::WindowInfo& info)
{
    m_window = glfwCreateWindow(info.Width, info.Height, "", nullptr, nullptr);
    glfwSetWindowRefreshCallback(m_window, refleshWindowCallback);
}

bool fj::GLFWWindow::shouldUpdate()const
{
    return (glfwWindowShouldClose(m_window) == GLFW_FALSE);
}

void fj::GLFWWindow::update()
{
    redrawWindow(m_window);
    glfwWaitEvents();
}

void fj::GLFWWindow::terminate()
{
    glfwDestroyWindow(m_window);
}
