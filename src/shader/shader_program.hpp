//
//  shader_program.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/23.
//
//

#ifndef shader_program_hpp
#define shader_program_hpp

#include <memory>

namespace fj {
    class FragmentShader;
    class VertexShader;
    class ShaderProgram;
}

class fj::ShaderProgram
{
public:
    ShaderProgram() = delete;
    ShaderProgram(std::shared_ptr<fj::FragmentShader>& fragmentShader, std::shared_ptr<fj::VertexShader>& vertexShader);
    ~ShaderProgram() = default;
    
    /** 
     * @return シェーダの作成に成功したか否か */
    bool createProgram();
    
    void load()const;
    void unload()const;
    GLuint getProgram()const;
private:
    std::shared_ptr<fj::FragmentShader> m_fragmentShader;
    
    std::shared_ptr<fj::VertexShader> m_vertexShader;
    
    GLuint m_program;
};

#endif /* shader_program_hpp */
