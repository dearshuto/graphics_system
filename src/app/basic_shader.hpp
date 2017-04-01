//
//  basic_shader.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/30.
//
//

#ifndef basic_shader_hpp
#define basic_shader_hpp

#include "object/formatted_object.hpp"
#include "window_system/window_manager.hpp"

namespace fj {
    class BasicShader;
}

class fj::BasicShader : public fj::WindowManager
{
    using Super = fj::WindowManager;
public:
    BasicShader() = default;
    ~BasicShader() = default;
    
    /** @copydoc Super::setup() */
    void setup()override;
    
    /** @copydoc Super::pollEvent()  */
    void pollEvent()override;
    
    /** @copydoc Super::setup() */
    void render()const override;
    
private:
    std::unique_ptr<fj::FormattedObject> m_object;
};

#endif /* basic_shader_hpp */
