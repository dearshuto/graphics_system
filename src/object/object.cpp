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
#include "shader/shader.hpp"
#include "object.hpp"

bool fj::Object::initialize()
{
    glGenBuffers(1, &m_VAO);
    glBindVertexArray(m_VAO);

    GLfloat vertices[] = {
        -0.5f, -0.5f,-0.5f,
         0.5f, -0.5f,-0.5f,
         0.5f, -0.5f, 0.5f,
        -0.5f, -0.5f, 0.5f,
        -0.5f,  0.5f,-0.5f,
         0.5f,  0.5f,-0.5f,
         0.5f,  0.5f, 0.5f,
        -0.5f,  0.5f, 0.5f,
    };

    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


    GLuint indices[] = {  // Note that we start from 0!
        0, 1, 2,  // First Triangle
        0, 2, 3,   // Second Triangle
        4, 7, 6,
        4, 6, 5,
        2, 7, 3,
        2, 6, 7,
        1, 6, 2,
        1, 5, 6,
        0, 5, 1,
        0, 4, 5,
        3, 7, 0,
        0, 7, 4
    };
    glGenBuffers(1, &m_EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
    
    glBindVertexArray(0);
    
    return true;
}

void fj::Object::draw(const fj::Shader &shader)const
{
    shader.load();
 
    const glm::mat4 kProjectionMatrix = glm::perspective(90.f, 4.0f/3.0f, 0.1f, 100.0f);
    auto projectionMatrixLocation = glGetUniformLocation(shader.getProgram(), "projectionMatrix");
    glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &kProjectionMatrix[0][0]);

    const glm::mat4 kViewMatrix = glm::translate(glm::vec3{0, 0, -3});
    auto viewMatrixLocation = glGetUniformLocation(shader.getProgram(), "viewMatrix");
    glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &kViewMatrix[0][0]);

    static glm::mat4 model(1.0);
    
    model =  glm::rotate(float(glfwGetTime()) * 3.0f, glm::vec3{1.0, 1.0, 0.0});
    auto modelMatrixLocation = glGetUniformLocation(shader.getProgram(), "modelMatrix");
    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &model[0][0]);

    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
    
    shader.unload();
}

void fj::Object::terminate()
{
    glDeleteBuffers(1, &m_EBO);
    glDeleteBuffers(1, &m_VBO);
    glDeleteBuffers(1, &m_VAO);
}

GLuint fj::Object::getVertexArrayObject()const
{
    return m_VAO;
}

GLuint fj::Object::getVertexBufferObject()const
{
    return m_VBO;
}

GLuint fj::Object::getElementBufferObject()const
{
    return m_EBO;
}
