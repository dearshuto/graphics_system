//
//  ImguiToolkitBuilder.cpp
//  OpenGL
//
//  Created by Shuto on 2017/03/30.
//
//

//#include "imgui_impl_glfw_gl3.h"
#include "component/imgui_text_editor.hpp"
#include "imgui_toolkit_builder.hpp"

std::unique_ptr<fj::TextEditor> fj::ImguiToolkitBuilder::buildTextEditor()const
{
    return std::make_unique<fj::ImguiTextEditor>();
}
