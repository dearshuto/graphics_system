//
//  glfw_window_system.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/17.
//
//

#ifndef glfw_window_system_hpp
#define glfw_window_system_hpp

#include "window_system/window_system.hpp"

namespace fj {
    class GLFWWindowSystem;
}

class fj::GLFWWindowSystem : public fj::WindowSystem
{
public:
    GLFWWindowSystem() = default;
    ~GLFWWindowSystem() = default;
    
    bool initialize()override;
    
    std::unique_ptr<fj::Window> generateWindow(const fj::WindowInfo& info)const override;
    
    void waitEvent()const override;

    void terminate()override;
};

#endif /* glfw_window_system_hpp */
