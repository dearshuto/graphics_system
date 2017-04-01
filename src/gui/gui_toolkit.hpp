//
//  gui_toolkit.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/30.
//
//

#ifndef gui_toolkit_hpp
#define gui_toolkit_hpp

#include <memory>

namespace fj {
    class TextEditor;
    class GUIToolkit;
}

class fj::GUIToolkit
{
protected:
    GUIToolkit() = default;
public:
    virtual~GUIToolkit() = default;
    
    virtual bool initialize() = 0;
    
    virtual void pollEvent() = 0;
    
    virtual void redraw()const = 0;
    
    virtual void terminate() = 0;
    
    virtual std::unique_ptr<fj::TextEditor> buildTextEditor()const = 0;
};

#endif /* gui_toolkit_hpp */
