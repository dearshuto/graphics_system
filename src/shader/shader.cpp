//
//  shader.cpp
//  OpenGL
//
//  Created by Shuto on 2017/03/17.
//
//

#include <iostream>
#include <string>
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

bool fj::Shader::compileShader(const std::string &source)
{
    // 引数が0のときは無視してくれる仕様なので, とりあえず消去関数を呼ぶ.
    glDeleteShader(m_shaderObject);
    
    // 成功すると正数が返る
    const GLchar* string = source.c_str();
    m_shaderObject = glCreateShader(getShaderType());
    
    glShaderSource(m_shaderObject, 1, &string, nullptr);
    glCompileShader(m_shaderObject);
    printError(m_shaderObject);
    
    return (0 < m_shaderObject);
}

GLuint fj::Shader::getUniformPosition(const std::string& variableName)const
{
    return glGetUniformLocation(0/*program*/, variableName.c_str());
}

GLuint fj::Shader::getShaderObject()const
{
    return m_shaderObject;
}
