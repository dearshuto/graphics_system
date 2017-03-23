//
//  object.cpp
//  OpenGL
//
//  Created by Shuto on 2017/03/17.
//
//

#define GLM_ENABLE_EXPERIMENTAL
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtx/transform.hpp>
#include "utility/OpenGL.h"
#include "shader/shader_program.hpp"
#include "object.hpp"

fj::Object::Object()
{
    glGenVertexArrays(1, &m_VAO);
}

fj::Object::~Object()
{
    glDeleteVertexArrays(1, &m_VAO);
}

void fj::Object::draw(const fj::ShaderProgram &shader)const
{
    shader.load();
 
    const glm::mat4 kProjectionMatrix = glm::perspective(90.f, 4.0f/3.0f, 0.1f, 100.0f);
    auto projectionMatrixLocation = glGetUniformLocation(shader.getProgram(), "projectionMatrix");
    glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &kProjectionMatrix[0][0]);

    const glm::mat4 kViewMatrix = glm::translate(glm::vec3{0, -1.0, -2.5});
    auto viewMatrixLocation = glGetUniformLocation(shader.getProgram(), "viewMatrix");
    glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &kViewMatrix[0][0]);

    
    glm::mat4 model =  glm::rotate(float(glfwGetTime()) * 1.5f, glm::vec3{0.0, 1.0, 0.0});
    auto modelMatrixLocation = glGetUniformLocation(shader.getProgram(), "modelMatrix");
    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &model[0][0]);

    glBindVertexArray(getVertexArrayObject());
    glDrawElements(GL_TRIANGLES, getDrawNum(), GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
    
    shader.unload();
}

GLuint fj::Object::getVertexArrayObject()const
{
    return m_VAO;
}
