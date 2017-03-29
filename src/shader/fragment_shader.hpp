//
//  fragment_shader.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/23.
//
//

#ifndef fragment_shader_hpp
#define fragment_shader_hpp

#include <string>
#include "shader.hpp"

namespace fj {
    class FragmentShader;
}

class fj::FragmentShader : public fj::Shader
{
public:
    FragmentShader() = default;
    ~FragmentShader() = default;
    
    GLenum getShaderType()const override;
};

#endif /* fragment_shader_hpp */
