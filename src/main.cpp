//
//  main.cpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/25.
//
//

#include <memory>
#include <string>
#include "window_system/glfw_glew_system.hpp"
#include "app/basic_shader.hpp"
#include "app/shader_editor.hpp"

int main(int argc, char** argv)
{
    std::unique_ptr<fj::WindowManager> app;
    
    if (argc < 2)
    {
        app.reset(new fj::BasicShader);
    }
    else
    {
        switch (std::stoi(argv[1]))
        {
            default:
            case 0:
                app.reset(new fj::BasicShader);
                break;
            case 1:
                app.reset(new fj::ShaderEditor);
                break;
        }
    }
    
    app->initialize({640, 480});
    app->mainloop();
    app->terminate();
        
    return 0;
}
