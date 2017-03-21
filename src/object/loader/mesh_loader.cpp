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
    return &m_vertex_normal[0];
}

GLsizeiptr fj::MeshLoader::getIndexBufferSize()const
{
    return m_indices.size() * sizeof(GLuint);
}

const GLuint*const fj::MeshLoader::getIndicesFrontPtr()const
{
    return &m_indices[0];
}
