//
//  glew_extension.cpp
//  OpenGL
//
//  Created by Shuto on 2017/03/19.
//
//

#include <GL/glew.h>
#include "glew_extension.hpp"

bool fj::GLEWExtension::initialize()
{
    return (glewInit() == GLEW_OK);
}
