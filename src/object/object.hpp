//
//  object.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/17.
//
//

#ifndef object_hpp
#define object_hpp

#include "utility/OpenGL.h"

namespace fj {
    class Shader;
    class Object;
}

class fj::Object
{
public:
    Object() = default;
    virtual~Object() = default;
    
    bool initialize();
    
    void draw(const fj::Shader& shader)const;
    
    GLuint getVAO()const;
    
private:
    GLuint m_VAO;
};

#endif /* object_hpp */
