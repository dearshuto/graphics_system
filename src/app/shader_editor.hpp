//
//  shader_editor.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/30.
//
//

#ifndef shader_editor_hpp
#define shader_editor_hpp

#include <memory>
#include "gui/component/text_editor.hpp"
#include "window_system/window_manager.hpp"

namespace fj {
    class ShaderEditor;
}

class fj::ShaderEditor : public fj::WindowManager
{
    using Super = fj::WindowManager;
public:
    ShaderEditor() = default;
    ~ShaderEditor() = default;

    
    /** @copydoc Super::setup() */
    void setup()override;
    
    /** @copydoc Super::pollEvent()  */
    void pollEvent()override;

    /** @copydoc Super::render() */
    void render()const override;
    
private:
    std::unique_ptr<fj::TextEditor> m_textEditor;
};

#endif /* shader_editor_hpp */
