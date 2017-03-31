//
//  gui_toolkit_builder.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/30.
//
//

#ifndef gui_toolkit_builder_hpp
#define gui_toolkit_builder_hpp

#include <memory>

namespace fj {
    class TextEditor;
    class GUIToolkitBuilder;
}

class fj::GUIToolkitBuilder
{
protected:
    GUIToolkitBuilder() = default;
    virtual~GUIToolkitBuilder() = default;
    
    virtual std::unique_ptr<fj::TextEditor> buildTextEditor()const = 0;
};

#endif /* gui_toolkit_builder_hpp */
