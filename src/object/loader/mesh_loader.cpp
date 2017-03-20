//
//  mesh_loader.cpp
//  OpenGL
//
//  Created by Shuto on 2017/03/20.
//
//

#include "mesh_loader.hpp"

GLsizeiptr fj::MeshLoader::getArrayBufferSize()const
{
    return m_vertex_normal.size() * sizeof(GLfloat);
}

const GLfloat*const fj::MeshLoader::getFrontPtr()const
{
    return &m_vertex_normal.front();
}
