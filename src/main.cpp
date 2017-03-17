//
//  main.cpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/25.
//
//

#include "window_system/window_manager.hpp"
#include "window_system/glfw/glfw_window_toolkit_builder.hpp"

int main(int argc, char** argv)
{
    fj::WindowManager windowManager;
    
    windowManager.initialize();
    windowManager.mainloop();
    windowManager.terminate();
        
    return 0;
}
