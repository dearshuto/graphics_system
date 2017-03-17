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
    class WindowSystemWxtension;
}

class fj::WindowSystemWxtension
{
protected:
    WindowSystemWxtension() = default;
public:
    virtual~WindowSystemWxtension() = default;
    
    virtual bool initialize() = 0;
};

#endif /* window_system_extension_hpp */
