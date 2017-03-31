//
//  imgui_text_editor.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/30.
//
//

#ifndef imgui_text_editor_hpp
#define imgui_text_editor_hpp

#include <string>
#include "gui/component/text_editor.hpp"

namespace fj {
    class ImguiTextEditor;
}

class fj::ImguiTextEditor : public fj::TextEditor
{
public:
    ImguiTextEditor() = default;
    ~ImguiTextEditor() = default;
    
    void draw()const override;
    
    void pollInputEvent()override;
    
private:
    std::string m_buffer;
};

#endif /* imgui_text_editor_hpp */
