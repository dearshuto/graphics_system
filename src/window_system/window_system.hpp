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
    
    virtual bool initialize() = 0;
    
    virtual std::unique_ptr<fj::Window> generateWindow(const fj::WindowInfo& info)const = 0;
    
    virtual void waitEvent()const = 0;
    
    virtual void terminate() = 0;
};

#endif /* window_system_hpp */
