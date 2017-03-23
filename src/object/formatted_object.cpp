//
//  formatted_object.cpp
//  OpenGL
//
//  Created by Shuto on 2017/03/20.
//
//

#include <GL/glew.h>
#include "formatted_object.hpp"

fj::FormattedObject::FormattedObject(std::unique_ptr<fj::MeshLoader> loader)
: m_loader(std::move(loader))
{
    
}

bool fj::FormattedObject::initialize()
{
    //---- VAOの設定 ---------------------------------------
    glBindVertexArray(getVertexArrayObject());

    // 頂点情報のセットアップ
    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    
    const auto kVerticesSize = getMeshLoaderPtr()->getArrayBufferSize();
    const auto kVerticesData = getMeshLoaderPtr()->getFrontPtr();
    glBufferData(GL_ARRAY_BUFFER, kVerticesSize, kVerticesData, GL_STATIC_DRAW);
    
    
    // インデクス情報のセットアップ
    glGenBuffers(1, &m_EBO);
    
    const auto kIndicesSize = getMeshLoaderPtr()->getIndexBufferSize();
    const auto kIndicesData = getMeshLoaderPtr()->getIndicesFrontPtr();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, kIndicesSize, kIndicesData, GL_STATIC_DRAW);
    
    // 頂点
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    // 法線
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
    
    //---- VAOの設定終わり ---------------------------------------
    glBindVertexArray(0);

    return true;
}

bool fj::FormattedObject::loadFromFile(const std::string &filename)
{
    return getMeshLoaderPtr() ? getMeshLoaderPtr()->loadFromFile(filename) : false;
}

GLsizei fj::FormattedObject::getDrawNum()const
{
    return m_loader->getDrawNum();
}

fj::MeshLoader*const fj::FormattedObject::getMeshLoaderPtr()
{
    return m_loader.get();
}

GLsizeiptr fj::FormattedObject::getArrayBufferSize()const
{
    return m_loader->getArrayBufferSize();
}

const GLfloat*const fj::FormattedObject::getFrontPtr()const
{
    return m_loader->getFrontPtr();
}
