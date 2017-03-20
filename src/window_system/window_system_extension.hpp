//
//  window_system_extension.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/17.
//
//

#ifndef window_system_extension_hpp
#define window_system_extension_hpp

namespace fj {
    class WindowSystemExtension;
}

class fj::WindowSystemExtension
{
protected:
    WindowSystemExtension() = default;
public:
    virtual~WindowSystemExtension() = default;
    
    virtual bool initialize() = 0;
};

#endif /* window_system_extension_hpp */
