//
//  main.cpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/25.
//
//

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(int argc, char** argv)
{
    if (glfwInit() == GL_FALSE)
    {
        glfwTerminate();
        return 0;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    auto window = glfwCreateWindow(640, 480, "", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    
    // Initialize GLEW
    const GLenum kGlewInitializeStatus = glewInit();
    if (kGlewInitializeStatus != GLEW_OK)
    {
        std::cout << glewGetErrorString(kGlewInitializeStatus) << std::endl;
        glfwTerminate();
        return 0;
    }
    
    while(!glfwWindowShouldClose(window))
    {
        glfwWaitEvents();
    }
    
    glfwTerminate();
    
    return 0;
}
