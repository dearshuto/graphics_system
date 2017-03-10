//
//  glfw_window.hpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/10.
//
//

#ifndef glfw_window_hpp
#define glfw_window_hpp

#include "window_system/window.hpp"

namespace fj {
    class GLFWWindow;
}

struct GLFWwindow;

class fj::GLFWWindow : public fj::Window
{
public:
    GLFWWindow() = delete;
    ~GLFWWindow() = default;
    
    GLFWWindow(const fj::WindowInfo& info);
    
    bool shouldUpdate()const override;
    void update()override;
    void terminate()override;
    
private:
    GLFWwindow* m_window;
};

#endif /* glfw_window_hpp */
