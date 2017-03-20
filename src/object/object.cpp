//
//  object.cpp
//  OpenGL
//
//  Created by Shuto on 2017/03/17.
//
//

#define GLM_ENABLE_EXPERIMENTAL
#include <gl/glew.h>
#include <glm/gtx/transform.hpp>
#include "utility/OpenGL.h"
#include "shader/shader.hpp"
#include "object.hpp"

bool fj::Object::initialize()
{
    glGenBuffers(1, &m_VAO);
    glBindVertexArray(m_VAO);

    GLfloat vertices[] = {
        0.5f,  0.5f, 0.0f,  // Top Right
        0.5f, -0.5f, 0.0f,  // Bottom Right
        -0.5f, -0.5f, 0.0f,  // Bottom Left
        -0.5f,  0.5f, 0.0f   // Top Left
    };

    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    

    GLuint indices[] = {  // Note that we start from 0!
        0, 1, 3,  // First Triangle
        1, 2, 3   // Second Triangle
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

    const glm::mat4 kModelMatrix = glm::translate(glm::vec3{-10, -10, -10});
    auto modelMatrixLocation = glGetUniformLocation(shader.getProgram(), "modelMatrix");
    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &kModelMatrix[0][0]);

    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
    
    shader.unload();
}

GLuint fj::Object::getVertexBufferObject()const
{
    return m_VBO;
}

GLuint fj::Object::getElementBufferObject()const
{
    return m_EBO;
}
