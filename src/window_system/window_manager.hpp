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
#include "window_container.hpp"
#include "window_system.hpp"

namespace fj {
    class WindowToolkitBuilder;
    struct WindowInfo;
    class WindowManager;
}

/// 表示するウィンドウを管理するクラス
class fj::WindowManager
{
public:
    WindowManager() = default;
    virtual~WindowManager() = default;
    
    WindowManager(const fj::WindowManager& other) = delete;
    fj::WindowManager& operator=(const fj::WindowManager& other) = delete;
        
    bool initialize();
    void mainloop();
    void terminate();
    
private:
    void generateWindow(const fj::WindowInfo& info);
    
private:
    const fj::WindowSystem& getWindowSystem()const;
    fj::WindowSystem*const getWindowSystemPtr();
private:
    std::unique_ptr<fj::Window> m_mainWindow;
    
    std::unique_ptr<fj::WindowSystem> m_windowSystem{nullptr};
};

#endif /* window_manager_hpp */
