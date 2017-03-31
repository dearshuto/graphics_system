//
//  window_system.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/17.
//
//

#ifndef window_system_hpp
#define window_system_hpp

#include <memory>
#include "utility/OpenGL.h"

namespace fj {
    class Window;
    struct WindowInfo;
    class WindowSystem;
}

class fj::WindowSystem
{
protected:
    WindowSystem() = default;
public:
    virtual~WindowSystem() = default;
    
    static fj::WindowSystem* GetInstance();
    
    virtual std::unique_ptr<fj::Window> generateWindow(const fj::WindowInfo& info)const = 0;
    
    virtual void pollEvent()const = 0;
    
    virtual void terminate() = 0;
    
//---- Extension Function
    virtual GLdouble getTime()const = 0;
    
    virtual void genVertexArrays(GLsizei n, GLuint* arrays)const = 0;
    
    virtual void deleteVertexArrays(GLsizei n, GLuint* arrays)const = 0;
    
    virtual void bindVertexArray(GLuint array)const = 0;
};

#endif /* window_system_hpp */
