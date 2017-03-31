//
//  polygon.hpp
//  OpenGL
//
//  Created by Shuto on 2017/04/01.
//
//

#ifndef polygon_hpp
#define polygon_hpp

#include <memory>
#include "object.hpp"

namespace fj {
    class ShaderProgram;
    class Polygon;
}

class fj::Polygon : public fj::Object
{
public:
    Polygon();
    virtual~Polygon();
    
    void render()const override;
    
private:
    void draw(const fj::ShaderProgram& shader)const;

public:
    GLuint getVertexArrayObject()const;
    
    virtual GLsizei getDrawNum()const = 0;
    
    void setShaderPrgram(std::shared_ptr<fj::ShaderProgram>& shaderProgram);
protected:
    const fj::ShaderProgram& getShaderProgram()const;
    
protected:
    GLuint m_VAO = -1;
    
    std::shared_ptr<fj::ShaderProgram> m_shaderProgram;
};

#endif /* polygon_hpp */
