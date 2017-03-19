//
//  shader.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/17.
//
//

#ifndef shader_hpp
#define shader_hpp

namespace fj {
    class Shader;
}

class fj::Shader
{
public:
    Shader() = default;
    virtual~Shader() = default;
    
    void load()const;
    void unload()const;
};

#endif /* shader_hpp */
