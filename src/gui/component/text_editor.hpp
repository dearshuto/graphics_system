//
//  text_editor.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/30.
//
//

#ifndef text_editor_hpp
#define text_editor_hpp

#include <string>
#include "gui.hpp"

namespace fj {
    class TextEditor;
}

class fj::TextEditor : public fj::GUI
{
public:
    TextEditor() = default;
    ~TextEditor() = default;
    
    void pollEvent()override;
    
    virtual const std::string& getText()const = 0;
    
private:
    virtual void pollInputEvent() = 0;
};

#endif /* text_editor_hpp */
