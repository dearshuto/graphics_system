//
//  glfw_glew_system.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/31.
//
//

#ifndef glfw_glew_system_hpp
#define glfw_glew_system_hpp

#include "window_system.hpp"

namespace fj {
    class GLFWGLEWSystem;
}

class fj::GLFWGLEWSystem : public fj::WindowSystem
{
    using Super = fj::WindowSystem;
protected:
    friend Super;
    GLFWGLEWSystem() = default;
public:
    ~GLFWGLEWSystem() = default;
    
//---- Override Functions ------------------------------------------------------
    GLdouble getTime()const override;

    void genVertexArrays(GLsizei n, GLuint* arrays)const override;
    
    void deleteVertexArrays(GLsizei n, GLuint* arrays)const override;
    
    void bindVertexArray(GLuint array)const override;

    std::unique_ptr<fj::Window> generateWindow(const fj::WindowInfo& info)const override;
    
    void pollEvent()const override;
    
    void terminate()override;
};

#endif /* glfw_glew_system_hpp */
