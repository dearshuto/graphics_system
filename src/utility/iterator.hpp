//
//  iterator.hpp
//  OpenGL
//
//  Created by Shuto Shikama on 2017/03/10.
//
//

#ifndef iterator_hpp
#define iterator_hpp

namespace fj {
    template<class T>
    class Iterator;
}

template<class T>
class fj::Iterator
{
protected:
    Iterator() = default;
public:
    virtual~Iterator() = default;
    
    virtual void reset() = 0;
    virtual void next() = 0;
    virtual bool isDone()const = 0;
    virtual const T& getCurrentItem()const = 0;
    virtual T*const getCurrentItemPtr() = 0;
};

#endif /* iterator_hpp */
