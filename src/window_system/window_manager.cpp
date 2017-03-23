//
//  window_manager.cpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/09.
//
//

#include "glfw/glfw_window_toolkit_builder.hpp"
#include "object/loader/wavefront_obj_loader.hpp"
#include "object/object.hpp"
#include "object/formatted_object.hpp"
#include "shader/shader.hpp"
#include "shader/shader_program.hpp"
#include "shader/fragment_shader.hpp"
#include "shader/vertex_shader.hpp"
#include "utility/iterator.hpp"
#include "utility/OpenGL.h"
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
    std::unique_ptr<fj::Shader> shader;
    
    // バーテックスシェーダのソースプログラム
    const std::string vsrc =
    "#version 330 core\n"
    "layout (location = 0) in vec3 position;\n"
    "layout (location = 1) in vec3 normal;\n"
    "out vec3 normalOut;\n"
    "uniform mat4 projectionMatrix;\n"
    "uniform mat4 viewMatrix;\n"
    "uniform mat4 modelMatrix;\n"
    "void main(void)\n"
    "{\n"
    "  normalOut = normal;\n"
    "  gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(position, 1.0);\n"
    "}\n";
    
    const std::string fsrc =
    "#version 330 core\n"
    "in vec3 normalOut;\n"
    "out vec4 color;\n"
    "void main(void)\n"
    "{\n"
    "  color = vec4(normalOut[0], normalOut[1], normalOut[2], 1.0);\n"
    "}\n";

    std::shared_ptr<fj::FragmentShader> fragmentShader{new fj::FragmentShader};
    fragmentShader->compileShader(fsrc);

    std::shared_ptr<fj::VertexShader> vertexShader{new fj::VertexShader};
    vertexShader->compileShader(vsrc);
    
    fj::ShaderProgram shaderProgram{fragmentShader, vertexShader};
    shaderProgram.createProgram();
    
    
    auto object = std::make_unique<fj::FormattedObject>(std::make_unique<fj::WavefrontObjLoader>());
    
//    shader->initialize();
    object->loadFromFile("armadillo.obj");
    object->initialize();
    
    glEnable(GL_DEPTH_TEST);
    
    while (m_mainWindow->shouldUpdate())
    {
        m_mainWindow->clear();
        
        object->draw(shaderProgram);
        
        m_mainWindow->swapBuffers();
        getWindowSystem().waitEvent();
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
