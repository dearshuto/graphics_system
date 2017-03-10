//
//  window_container.hpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/09.
//
//

#ifndef window_container_hpp
#define window_container_hpp

#include <memory>
#include "window.hpp"

namespace fj {
    template<class T> class Iterator;
    class WindowContainer;
}

class fj::WindowContainer
{
public:
    WindowContainer() = default;
    virtual~WindowContainer() = default;
    
    virtual void addWindow(std::unique_ptr<fj::Window> window) = 0;
    
    virtual std::unique_ptr<fj::Iterator<fj::Window>> iterator() = 0;
};

#endif /* window_container_hpp */
