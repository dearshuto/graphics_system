//
//  object.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/17.
//
//

#ifndef object_hpp
#define object_hpp

#include <string>
#include <vector>
#include "utility/OpenGL.h"

namespace fj {
    class Shader;
    class Object;
}

/// 三角ポリゴンのみで構成されるメッシュ
class fj::Object
{
public:
    Object();
    virtual~Object();
    
    virtual bool initialize() = 0;
    
    void draw(const fj::Shader& shader)const;
    
    GLuint getVertexArrayObject()const;
    
    virtual GLsizei getDrawNum()const = 0;
    
protected:
    GLuint m_VAO;
};

#endif /* object_hpp */
