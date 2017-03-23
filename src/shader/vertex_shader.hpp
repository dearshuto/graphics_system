//
//  vertex_shader.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/23.
//
//

#ifndef vertex_shader_hpp
#define vertex_shader_hpp

#include "shader.hpp"

namespace fj {
    class VertexShader;
}

class fj::VertexShader : public fj::Shader
{
public:
    VertexShader() = default;
    ~VertexShader() = default;
    
    GLenum getShaderType()const override;
};

#endif /* vertex_shader_hpp */
