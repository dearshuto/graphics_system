//
//  glfw_window_container.hpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/10.
//
//

#ifndef glfw_window_container_hpp
#define glfw_window_container_hpp

#include <memory>
#include <vector>

#include "utility/iterator.hpp"
#include "window_system/window_container.hpp"
#include "glfw_window.hpp"

namespace fj {
    class GLFWWindowContainer;
}

class fj::GLFWWindowContainer : public fj::WindowContainer
{
    class Iterator : public fj::Iterator<fj::Window>
    {
    public:
        Iterator() = delete;
        virtual~Iterator() = default;
        Iterator(fj::GLFWWindowContainer*const parent);
        
        void reset()override;
        void next()override;
        bool isDone()const override;
        const fj::Window& getCurrentItem()const override;
        fj::Window*const getCurrentItemPtr() override;
    private:
        fj::GLFWWindowContainer*const m_parent;
        std::vector<std::unique_ptr<fj::GLFWWindow>>::iterator m_now;
    };
public:
    GLFWWindowContainer() = default;
    virtual~GLFWWindowContainer() = default;
    
    void addWindow(std::unique_ptr<fj::Window> window)override;
    std::unique_ptr<fj::Iterator<fj::Window>> iterator()override;
    
private:
    std::vector<std::unique_ptr<fj::GLFWWindow>> m_windows;
};

#endif /* glfw_window_container_hpp */
