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
    class ShaderProgram;
    class Object;
}

/// 三角ポリゴンのみで構成されるメッシュ
class fj::Object
{
public:
    Object() = default;
    virtual~Object() = default;
    
    virtual void pollEvent() = 0;
    
    virtual void render()const = 0;    
};

#endif /* object_hpp */
