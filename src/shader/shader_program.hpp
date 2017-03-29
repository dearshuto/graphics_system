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
#include <string>

namespace fj {
    class FragmentShader;
    class VertexShader;
    class ShaderProgram;
}

/// 以下の3つの変換行列をサポートするシェーダ
/// - Projection Matrix
/// - View Matrix
/// - Model Matrix
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
    
    GLint getProjectionMatrixLocation()const;
    
    GLint getViewMatrixLocation()const;
    
    GLint getModelMatrixLocation()const;
    
    GLuint getProgram()const;
    
protected:
    GLint getUniformLocation(const std::string& uniformName)const;
    
private:
    std::shared_ptr<fj::FragmentShader> m_fragmentShader;
    
    std::shared_ptr<fj::VertexShader> m_vertexShader;
    
    GLuint m_program;
};

#endif /* shader_program_hpp */
