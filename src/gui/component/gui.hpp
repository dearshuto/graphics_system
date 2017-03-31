//
//  gui.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/30.
//
//

#ifndef gui_h
#define gui_h

namespace fj {
    class GUI;
}

class fj::GUI
{
protected:
    GUI() = default;
public:
    virtual~GUI() = default;
    
    virtual void pollEvent() = 0;
    
    virtual void draw()const = 0;
};

#endif /* gui_h */
