//
//  window_container.hpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/09.
//
//

#ifndef window_container_hpp
#define window_container_hpp

namespace fj {
    class WindowContainer;
}

class fj::WindowContainer
{
public:
    WindowContainer() = default;
    virtual~WindowContainer() = default;
};

#endif /* window_container_hpp */
