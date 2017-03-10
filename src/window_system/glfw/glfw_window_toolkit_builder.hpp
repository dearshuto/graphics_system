//
//  glfw_window_toolkit_builder.hpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/09.
//
//

#ifndef glfw_window_toolkit_builder_hpp
#define glfw_window_toolkit_builder_hpp

#include "window_system/window_toolkit_builder.hpp"

namespace fj {
    class GLFWWindowToolkitBuilder;
}

class fj::GLFWWindowToolkitBuilder : public fj::WindowBuilder
{
public:
    GLFWWindowToolkitBuilder() = default;
    virtual~GLFWWindowToolkitBuilder() = default;
    
    std::unique_ptr<fj::WindowGenerator> createWindowGenerator()const override;
    std::unique_ptr<fj::WindowContainer> createWindowContainer()const override;
};

#endif /* glfw_window_toolkit_builder_hpp */
