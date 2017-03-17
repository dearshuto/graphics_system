//
//  window_toolkit_builder.hpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/09.
//
//

#ifndef window_toolkit_builder_hpp
#define window_toolkit_builder_hpp

#include <memory>

namespace fj {
    class Window;
    struct WindowInfo;
    class WindowSystem;
    class WindowSystemExtension;
    class WindowContainer;
    class WindowToolkitBuilder;
}

class fj::WindowToolkitBuilder
{
protected:
    WindowToolkitBuilder() = default;
public:
    virtual~WindowToolkitBuilder() = default;
    
    WindowToolkitBuilder(const fj::WindowToolkitBuilder& other) = delete;
    fj::WindowToolkitBuilder& operator=(const fj::WindowToolkitBuilder& other) = delete;
    
    virtual std::unique_ptr<fj::WindowSystem> createWindowSystem()const = 0;
    
    virtual bool initializeSystemExtension() = 0;

    virtual std::unique_ptr<fj::WindowContainer> createWindowContainer()const = 0;
};

#endif /* window_toolkit_builder_hpp */
