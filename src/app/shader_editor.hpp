//
//  shader_editor.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/30.
//
//

#ifndef shader_editor_hpp
#define shader_editor_hpp

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
    
    
    /** @copydoc Super::render() */
    void render()const override;
};

#endif /* shader_editor_hpp */
