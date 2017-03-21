//
//  wavefront_obj_loader.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/20.
//
//

#ifndef wavefront_obj_loader_hpp
#define wavefront_obj_loader_hpp

#include "mesh_loader.hpp"

namespace fj {
    class WavefrontObjLoader;
}

class fj::WavefrontObjLoader : public fj::MeshLoader
{
public:
    WavefrontObjLoader() = default;
    ~WavefrontObjLoader() = default;
    
    /** @copydoc fj::MeshLoader::loadFromFile() */
    bool loadFromFile(const std::string& filename)override;
    
    GLsizei getDrawNum()const override;
};

#endif /* wavefront_obj_loader_hpp */
