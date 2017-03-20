//
//  glew_extension.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/19.
//
//

#ifndef glew_extension_hpp
#define glew_extension_hpp

#include "window_system/window_system_extension.hpp"

namespace fj {
    class GLEWExtension;
}

class fj::GLEWExtension : public fj::WindowSystemExtension
{
public:
    GLEWExtension() = default;
    ~GLEWExtension() = default;
    
    bool initialize()override;
};

#endif /* glew_extension_hpp */
