//
//  ImguiToolkitBuilder.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/30.
//
//

#ifndef ImguiToolkitBuilder_hpp
#define ImguiToolkitBuilder_hpp

#include "gui/gui_toolkit_builder.hpp"

namespace fj {
    class ImguiToolkitBuilder;
}

class fj::ImguiToolkitBuilder : public fj::GUIToolkitBuilder
{
public:
    ImguiToolkitBuilder() = default;
    ~ImguiToolkitBuilder() = default;
    
    std::unique_ptr<fj::TextEditor> buildTextEditor()const override;
};

#endif /* ImguiToolkitBuilder_hpp */
