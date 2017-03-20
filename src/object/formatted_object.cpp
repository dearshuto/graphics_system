//
//  formatted_object.cpp
//  OpenGL
//
//  Created by Shuto on 2017/03/20.
//
//

#include "formatted_object.hpp"

fj::FormattedObject::FormattedObject(std::unique_ptr<fj::MeshLoader> loader)
: m_loader(std::move(loader))
{
    
}

bool fj::FormattedObject::loadFromFile(const std::string &filename)
{
    return getMeshLoaderPtr() ? getMeshLoaderPtr()->loadFromFile(filename) : false;
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
