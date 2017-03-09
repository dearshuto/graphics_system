//
//  window_builder.hpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/09.
//
//

#ifndef window_builder_hpp
#define window_builder_hpp

#include <memory>

namespace fj {
    class Window;
    class WindowContainer;
    class WindowGenerator;
    struct WindowInfo;
    class WindowBuilder;
}

class fj::WindowBuilder
{
protected:
    WindowBuilder() = default;
public:
    virtual~WindowBuilder() = default;
    
    WindowBuilder(const fj::WindowBuilder& other) = delete;
    fj::WindowBuilder& operator=(const fj::WindowBuilder& other) = delete;
    
    virtual std::unique_ptr<fj::WindowGenerator> createWindowGenerator()const = 0;
    virtual std::unique_ptr<fj::WindowContainer> createWindowContainer()const = 0;
};

#endif /* window_builder_hpp */
