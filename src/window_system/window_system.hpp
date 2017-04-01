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
#include "window.hpp"

namespace fj {
    class GUIToolkit;
    class WindowSystem;
}

class fj::WindowSystem
{
protected:
    WindowSystem() = default;
public:
    virtual~WindowSystem() = default;
    
    WindowSystem(const fj::WindowSystem& other) = delete;
    WindowSystem& operator=(const fj::WindowSystem& other) = delete;
    
    static fj::WindowSystem* GetInstance();
    
//---- Window Toolkit ----------------------------------------------------------
    virtual bool generateWindow(const fj::WindowInfo& info) = 0;
    
    virtual std::unique_ptr<fj::GUIToolkit> generateGUIToolkit()const = 0;
    
    virtual void pollEvent()const = 0;
    
    virtual void terminate() = 0;
    
    //---- Extension Function
    virtual GLdouble getTime()const = 0;
    
    virtual void genVertexArrays(GLsizei n, GLuint* arrays)const = 0;
    
    virtual void deleteVertexArrays(GLsizei n, GLuint* arrays)const = 0;
    
    virtual void bindVertexArray(GLuint array)const = 0;
    
public:
    const fj::Window& getWindow()const;
    fj::Window*const getWindowPtr();
    
protected:
    void setWindow(std::unique_ptr<fj::Window> window);
    
private:
    std::unique_ptr<fj::Window> m_window;
};

#endif /* window_system_hpp */
