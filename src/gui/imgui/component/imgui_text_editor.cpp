//
//  imgui_text_editor.cpp
//  OpenGL
//
//  Created by Shuto on 2017/03/30.
//
//

#include <imgui.h>
#include <GLFW/glfw3.h>
#include "imgui_text_editor.hpp"

void fj::ImguiTextEditor::pollInputEvent()
{
    char buffer[256];
    ImGui::InputTextMultiline("label", buffer, 256);
    m_buffer = buffer;
}

void fj::ImguiTextEditor::draw()const
{
    
}

const std::string& fj::ImguiTextEditor::getText()const
{
    return m_buffer;
}
