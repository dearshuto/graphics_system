//
//  imgui_toolkit.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/30.
//
//

#ifndef imgui_toolkit_hpp
#define imgui_toolkit_hpp

#include "gui/gui_toolkit.hpp"

namespace fj {
    class ImguiToolkit;
}

class fj::ImguiToolkit : public fj::GUIToolkit
{
public:
    ImguiToolkit() = default;
    ~ImguiToolkit() = default;
    
    bool initialize()override;
    
    void pollEvent()override;
    
    void redraw()const override;

    void terminate()override;
    
    std::unique_ptr<fj::TextEditor> buildTextEditor()const override;
};

#endif /* imgui_toolkit_hpp */
