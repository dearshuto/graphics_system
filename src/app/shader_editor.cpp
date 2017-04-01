//
//  shader_editor.cpp
//  OpenGL
//
//  Created by Shuto on 2017/03/30.
//
//

#include "gui/component/text_editor.hpp"
#include "utility/OpenGL.h"
#include "shader_editor.hpp"

void fj::ShaderEditor::setup()
{
    m_textEditor = getGUIToolkitPtr()->buildTextEditor();
}

void fj::ShaderEditor::pollEvent()
{
    m_textEditor->pollEvent();
}

void fj::ShaderEditor::render()const
{
    const float kR = 1.0, kG = 1.0f, kB = 1.0f, kA = 1.0f;
    glClearColor(kR, kG, kB, kA);
    glClear(GL_COLOR_BUFFER_BIT);

    m_textEditor->draw();
}
