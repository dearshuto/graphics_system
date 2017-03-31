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
#include "window.hpp"

namespace fj {
    class WindowManager;
}

/// 表示するウィンドウを管理するクラス
/** ウィンドウは1つに限定する. */
class fj::WindowManager
{
public:
//---- Default Constructor/Destructor ------------------------------------------
    WindowManager() = default;
    virtual~WindowManager() = default;
    
    
//---- Copy Functions ----------------------------------------------------------
    WindowManager(const fj::WindowManager& other) = delete;
    fj::WindowManager& operator=(const fj::WindowManager& other) = delete;
    
    
//---- Public FUnctions --------------------------------------------------------
    bool initialize(const fj::WindowInfo& windowInfo);
    void mainloop();
    void terminate();
    
    
//---- Virtual Functions -------------------------------------------------------
private:
    /** アプリケーションの初期セッティング.
     * @pre Windowが1つ作成されている. */
    virtual void setup() = 0;
    
    /** ウィンドウに描画する. この関数は毎フレーム呼ばれる.
     * @pre イベントが検出されている. */
    virtual void render()const = 0;

    
//---- Protected Getters -------------------------------------------------------
protected:
    const fj::Window& getWindow()const;
    fj::Window*const getWindowPtr();
    
    
//---- Private Functions -------------------------------------------------------
private:
    /** ウィンドウの更新or閉じるを判定する. */
    bool shouldUpdate()const;
    
    /** イベントを処理する */
    virtual void pollEvent();
    
    /**  */
    void swapBuffers()const;

    
//---- Member Variables --------------------------------------------------------
private:
    std::unique_ptr<fj::Window> m_window;
};

#endif /* window_manager_hpp */
