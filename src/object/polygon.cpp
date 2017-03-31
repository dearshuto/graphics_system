//
//  polygon.cpp
//  OpenGL
//
//  Created by Shuto on 2017/04/01.
//
//

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>
#include "shader/shader_program.hpp"
#include "window_system/window_system.hpp"
#include "polygon.hpp"

fj::Polygon::Polygon()
{
    fj::WindowSystem::GetInstance()->genVertexArrays(1, &m_VAO);
}

fj::Polygon::~Polygon()
{
    fj::WindowSystem::GetInstance()->deleteVertexArrays(1, &m_VAO);
}

void fj::Polygon::render()const
{
    glUseProgram(getShaderProgram().getProgram());
    
    const glm::mat4 kProjectionMatrix = glm::perspective(90.f, 4.0f/3.0f, 0.1f, 100.0f);
    auto projectionMatrixLocation = getShaderProgram().getProjectionMatrixLocation();
    glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &kProjectionMatrix[0][0]);
    
    const glm::mat4 kViewMatrix = glm::translate(glm::vec3{0, -1.0, -2.5});
    auto viewMatrixLocation = getShaderProgram().getViewMatrixLocation();
    glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &kViewMatrix[0][0]);
    
    const GLfloat kTime = fj::WindowSystem::GetInstance()->getTime();
    glm::mat4 model =  glm::rotate(kTime * 1.5f, glm::vec3{0.0, 1.0, 0.0});
    auto modelMatrixLocation = getShaderProgram().getModelMatrixLocation();
    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &model[0][0]);
    
    fj::WindowSystem::GetInstance()->bindVertexArray(getVertexArrayObject());
    glDrawElements(GL_TRIANGLES, getDrawNum(), GL_UNSIGNED_INT, nullptr);
    fj::WindowSystem::GetInstance()->bindVertexArray(0);
}

GLuint fj::Polygon::getVertexArrayObject()const
{
    return m_VAO;
}

const fj::ShaderProgram& fj::Polygon::getShaderProgram()const
{
    return *m_shaderProgram;
}

void fj::Polygon::setShaderPrgram(std::shared_ptr<fj::ShaderProgram> &shaderProgram)
{
    m_shaderProgram = shaderProgram;
}
