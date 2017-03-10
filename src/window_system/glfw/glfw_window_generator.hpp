//
//  glfw_window_generator.hpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/10.
//
//

#ifndef glfw_window_generator_hpp
#define glfw_window_generator_hpp

#include "window_system/window_generator.hpp"

namespace fj {
    struct WindowInfo;
    class GLFWWindowGenerator;
}

class fj::GLFWWindowGenerator : public fj::WindowGenerator
{
public:
    GLFWWindowGenerator() = default;
    ~GLFWWindowGenerator() = default;
    
    bool initialize()override;
    
    void terminate()override;
    
    std::unique_ptr<fj::Window> generateWindow(const fj::WindowInfo& windowInfo)const override;

};

#endif /* glfw_window_generator_hpp */
