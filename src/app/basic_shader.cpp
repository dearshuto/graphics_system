//
//  basic_shader.cpp
//  OpenGL
//
//  Created by Shuto on 2017/03/30.
//
//

#include "object/loader/wavefront_obj_loader.hpp"
#include "object/object.hpp"
#include "object/formatted_object.hpp"
#include "shader/shader.hpp"
#include "shader/shader_program.hpp"
#include "shader/fragment_shader.hpp"
#include "shader/vertex_shader.hpp"
#include "utility/iterator.hpp"
#include "utility/OpenGL.h"
#include "window_system/window_system.hpp"
#include "basic_shader.hpp"

void fj::BasicShader::setup()
{
    std::unique_ptr<fj::Shader> shader;
    
    // バーテックスシェーダのソースプログラム
    const std::string vsrc =
    "#version 330 core\n"
    "layout (location = 0) in vec3 position;\n"
    "layout (location = 1) in vec3 normal;\n"
    "out vec3 normalOut;\n"
    "out vec3 fragPos;\n"
    "uniform mat4 projectionMatrix;\n"
    "uniform mat4 viewMatrix;\n"
    "uniform mat4 modelMatrix;\n"
    "void main(void)\n"
    "{\n"
    "  normalOut = normal;\n"
    "  fragPos = vec3(modelMatrix * vec4(position, 1.0f));\n"
    "  gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(position, 1.0);\n"
    "}\n";
    
    const std::string fsrc =
    "#version 330 core\n"
    "out vec4 color;\n"
    "in vec3 normalOut;\n"
    "in vec3 fragPos;\n"
    "void main(void)\n"
    "{\n"
    "  vec3 lightColor = vec3(1.0, 0.8, 0.6);\n"
    "  vec3 objectColor = vec3(1.0, 1.0, 1.0);\n"
    "  vec3 norm = normalize(normalOut);\n"
    "  vec3 lightDirection = normalize(vec3(0, 10, -10) - fragPos);\n"
    "  vec3 diffuse = max(dot(norm, lightDirection), 0.0) * lightColor;\n"
    "  vec3 ambient = vec3(0.1);\n"
    "  vec3 result = (diffuse + ambient) * objectColor;\n"
    "  color = vec4(result.r, result.g, result.b, 1.0);\n"
    "}\n";
    
    std::shared_ptr<fj::FragmentShader> fragmentShader{new fj::FragmentShader};
    fragmentShader->compileShader(fsrc);
    
    std::shared_ptr<fj::VertexShader> vertexShader{new fj::VertexShader};
    vertexShader->compileShader(vsrc);
    
    std::shared_ptr<fj::ShaderProgram> shaderProgram = std::make_shared<fj::ShaderProgram>(fragmentShader, vertexShader);
    shaderProgram->createProgram();
    
    auto loader = std::make_unique<fj::WavefrontObjLoader>();
    m_object = std::make_unique<fj::FormattedObject>(std::move(loader));
    m_object->loadFromFile("armadillo.obj");
    m_object->initialize();
    m_object->setShaderPrgram(shaderProgram);
}

void fj::BasicShader::render()const
{
    const float kR = 1.0f, kG = 1.0f, kB = 1.0f, kA = 1.0f;
    glClearColor(kR, kG, kB, kA);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    
    m_object->render();
}
