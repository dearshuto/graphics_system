//
//  shader_program.cpp
//  OpenGL
//
//  Created by Shuto on 2017/03/23.
//
//

#include <iostream>
#include "utility/OpenGL.h"
#include "fragment_shader.hpp"
#include "vertex_shader.hpp"
#include "shader_program.hpp"

fj::ShaderProgram::ShaderProgram(std::shared_ptr<fj::FragmentShader>& fragmentShader, std::shared_ptr<fj::VertexShader>& vertexShader)
: m_fragmentShader(fragmentShader)
, m_vertexShader(vertexShader)
{
    
}

// プログラムオブジェクトのリンク結果を表示する
static GLboolean printProgramInfoLog(GLuint program)
{
    // リンク結果を取得する
    GLint status;
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    if (status == GL_FALSE) std::cout << "Link Error" << std::endl;
    
    // シェーダのリンク時のログの長さを取得する
    GLsizei bufSize;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH , &bufSize);
    
    if (bufSize > 1)
    {
        // シェーダのリンク時のログの内容を取得する
        GLchar *infoLog = new GLchar[bufSize];
        GLsizei length;
        glGetProgramInfoLog(program, bufSize, &length, infoLog);
        std::cout << infoLog << std::endl;
        delete[] infoLog;
    }
    
    return (GLboolean)status;
}

bool fj::ShaderProgram::createProgram()
{
    m_program = glCreateProgram();
    
    glAttachShader(m_program, m_vertexShader->getShaderObject());
    glAttachShader(m_program, m_fragmentShader->getShaderObject());
    
    // リンク前にアトリビュートのインデクスを指定する方法.
    glBindAttribLocation(m_program, 0, "position");
    
    glLinkProgram(m_program);
    
    // NOTE: リンク後にこの関数でアトリビュートのインデクスを取得する方法もある.
    //glGetAttribLocation
    
    return false;
}

GLint fj::ShaderProgram::getUniformLocation(const std::string &uniformName)const
{
    return glGetUniformLocation(getProgram(), uniformName.c_str());
}

GLint fj::ShaderProgram::getProjectionMatrixLocation()const
{
    return getUniformLocation("projectionMatrix");
}

GLint fj::ShaderProgram::getViewMatrixLocation()const
{
    return getUniformLocation("viewMatrix");
}

GLint fj::ShaderProgram::getModelMatrixLocation()const
{
    return getUniformLocation("modelMatrix");
}

void fj::ShaderProgram::load()const
{
    glUseProgram(m_program);
}

void fj::ShaderProgram::unload()const
{
    glUseProgram(0);
}

GLuint fj::ShaderProgram::getProgram()const
{
    return m_program;
}
