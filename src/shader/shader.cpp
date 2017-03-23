//
//  shader.cpp
//  OpenGL
//
//  Created by Shuto on 2017/03/17.
//
//

#include <iostream>
#include <Gl/glew.h>
#include "shader.hpp"

void printError(const GLuint obj)
{
    GLint status;
    glGetShaderiv(obj, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        std::cout << "error" << std::endl;
    }
    GLsizei bufSize;
    glGetShaderiv(obj, GL_INFO_LOG_LENGTH , &bufSize);
    
    if (bufSize > 1)
    {
        // シェーダのコンパイル時のログの内容を取得する
        GLchar *infoLog = new GLchar[bufSize];
        GLsizei length;
        glGetShaderInfoLog(obj, bufSize, &length, infoLog);
        std::cout << infoLog << std::endl;
        delete[] infoLog;
    }

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

// プログラムオブジェクトの作成
static GLuint createProgram(const char *vsrc, const char *pv, const char *fsrc, const char *fc)
{
    printf("Supported GLSL version is %s.\n", (char *)glGetString(GL_SHADING_LANGUAGE_VERSION));
    
    // バーテックスシェーダのシェーダオブジェクト
    GLuint vobj = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vobj, 1, &vsrc, NULL);
    glCompileShader(vobj);
    printError(vobj);
    
    // フラグメントシェーダのシェーダオブジェクトの作成
    GLuint fobj = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fobj, 1, &fsrc, NULL);
    glCompileShader(fobj);
    printError(fobj);
    
    // シェーダオブジェクトの取り付け
    GLuint program = glCreateProgram();
    glAttachShader(program, vobj);
    glDeleteShader(vobj);
    glAttachShader(program, fobj);
    glDeleteShader(fobj);
    
    // プログラムオブジェクトのリンク
    glBindAttribLocation(program, 0, pv);
//    glBindFragDataLocationEXT(program, 0, fc);
    glLinkProgram(program);
    printProgramInfoLog(program);
    
    
    return program;
}

bool fj::Shader::initialize()
{
    // バーテックスシェーダのソースプログラム
    static const GLchar vsrc[] =
    "#version 120\n"
    "attribute vec3 position;\n"
    "attribute vec3 normal;\n"
    "varying vec3 normalOut;\n"
    "uniform mat4 projectionMatrix;\n"
    "uniform mat4 viewMatrix;\n"
    "uniform mat4 modelMatrix;\n"
    "void main(void)\n"
    "{\n"
    "  normalOut = normal;\n"
    "  gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(position, 1.0);\n"
    "}\n";
    
    // フラグメントシェーダのソースプログラム
    static const GLchar fsrc[] =
    "#version 120\n"
    "varying vec3 normalOut;\n"
    "void main(void)\n"
    "{\n"
    "  gl_FragColor = vec4(normalOut[0], normalOut[1], normalOut[2], 1.0);\n"
    "}\n";
    
    // プログラムオブジェクトの作成
    m_program = createProgram(vsrc, "position", fsrc, "fc");
    
    return true;
}

void fj::Shader::load()const
{
    glUseProgram(m_program);
}

void fj::Shader::unload()const
{
    glUseProgram(0);
}

GLuint fj::Shader::getUniformPosition(const std::string& variableName)const
{
    return glGetUniformLocation(0/*program*/, variableName.c_str());
}

GLuint fj::Shader::getProgram()const
{
    return m_program;
}
