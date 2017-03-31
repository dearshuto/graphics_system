//
//  window.hpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/10.
//
//

#ifndef window_hpp
#define window_hpp

#include <cstdint>

namespace fj {
    struct WindowInfo;
    class Window;
}

struct fj::WindowInfo
{
    std::uint32_t Width = 640;
    std::uint32_t Height = 480;
};

class fj::Window
{
public:
    Window() = default;
    virtual~Window() = default;
    
    virtual bool shouldUpdate()const = 0;
    virtual void swapBuffers()const = 0;
    virtual void terminate() = 0;
};

#endif /* window_hpp */
