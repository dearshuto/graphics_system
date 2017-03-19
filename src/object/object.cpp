//
//  object.cpp
//  OpenGL
//
//  Created by Shuto on 2017/03/17.
//
//

#include "utility/OpenGL.h"
#include "shader/shader.hpp"
#include "object.hpp"

void fj::Object::draw(const fj::Shader &shader)const
{
    shader.load();
    
    glBindVertexArrayAPPLE(getVAO());
    
    shader.unload();
}

GLuint fj::Object::getVAO()const
{
    return m_VAO;
}
