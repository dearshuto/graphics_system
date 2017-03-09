//
//  glfw_window_builder.hpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/09.
//
//

#ifndef glfw_window_builder_hpp
#define glfw_window_builder_hpp

#include "window_system/window_builder.hpp"

namespace fj {
    class GLFWWindowBuilder;
}

class fj::GLFWWindowBuilder : public fj::WindowBuilder
{
public:
    GLFWWindowBuilder() = default;
    virtual~GLFWWindowBuilder() = default;
    
    std::unique_ptr<fj::WindowGenerator> createWindowGenerator()const override;
    std::unique_ptr<fj::WindowContainer> createWindowContainer()const override;
};

#endif /* glfw_window_builder_hpp */
