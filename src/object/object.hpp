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
    Object() = default;
    virtual~Object() = default;
    
    bool initialize();
    
    void terminate();
    
    void draw(const fj::Shader& shader)const;
    
    GLuint getVertexArrayObject()const;
    
    GLuint getVertexBufferObject()const;
    
    GLuint getElementBufferObject()const;
    
private:
    GLuint m_VAO;
    
    GLuint m_VBO;
    
    GLuint m_EBO;
};

#endif /* object_hpp */
