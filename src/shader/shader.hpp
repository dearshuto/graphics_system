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
    
    GLuint getUniformPosition(const std::string& variableName)const;
    
    GLuint getShaderObject()const;
    
    bool compileShader(const std::string& source);
    
protected:
    virtual GLenum getShaderType()const = 0;
    
private:
    GLuint m_shaderObject = 0;
};

#endif /* shader_hpp */
