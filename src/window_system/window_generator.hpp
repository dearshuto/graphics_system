//
//  window_generator.hpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/09.
//
//

#ifndef window_generator_hpp
#define window_generator_hpp

#include <memory>

namespace fj {
    class Window;
    struct WindowInfo;
    class WindowGenerator;
}

class fj::WindowGenerator
{
public:
    WindowGenerator() = default;
    virtual~WindowGenerator() = default;
    
    virtual bool initialize() = 0;
    
    virtual void terminate() = 0;
    
    virtual std::unique_ptr<fj::Window> generateWindow(const fj::WindowInfo& windowInfo)const = 0;
};

#endif /* window_generator_hpp */
