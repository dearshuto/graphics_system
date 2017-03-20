//
//  shader.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/17.
//
//

#ifndef shader_hpp
#define shader_hpp

#include <string>
#include "utility/OpenGL.h"

namespace fj {
    class Shader;
}

class fj::Shader
{
public:
    Shader() = default;
    virtual~Shader() = default;
    
    bool initialize();
    
    void load()const;
    void unload()const;
    
    GLuint getUniformPosition(const std::string& variableName)const;
    
    GLuint getProgram()const;
    
private:
    GLuint m_program;
};

#endif /* shader_hpp */
