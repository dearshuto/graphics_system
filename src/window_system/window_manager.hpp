//
//  window_manager.hpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/09.
//
//

#ifndef window_manager_hpp
#define window_manager_hpp

#include <memory>
#include "window_builder.hpp"
#include "window_container.hpp"
#include "window_generator.hpp"

namespace fj {
    class WindowManager;
}

/// 表示するウィンドウを管理するクラス
class fj::WindowManager
{
public:
    WindowManager() = delete;
    virtual~WindowManager() = default;
    
    WindowManager(const fj::WindowManager& other) = delete;
    fj::WindowManager& operator=(const fj::WindowManager& other) = delete;

    WindowManager(std::unique_ptr<fj::WindowBuilder> windowBuilder);
        
    bool initialize();
    void mainloop();
    void terminate();
    
private:
    const fj::WindowContainer& getWindowContainer()const;
    fj::WindowContainer*const getWindowContainerPtr();
    
    const fj::WindowGenerator& getWindowGenerator()const;
    fj::WindowGenerator*const getWindowGeneratorPtr();
private:
    std::unique_ptr<fj::WindowContainer> m_windowContainer{nullptr};
    std::unique_ptr<fj::WindowGenerator> m_windowGenerator{nullptr};
};

#endif /* window_manager_hpp */
