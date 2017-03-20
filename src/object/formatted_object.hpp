//
//  formatted_object.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/20.
//
//

#ifndef formatted_object_hpp
#define formatted_object_hpp

#include "loader/mesh_loader.hpp"
#include "object.hpp"
#include <memory>

namespace fj {
    class FormattedObject;
}

/// 外部のメッシュデータから構成されるオブジェクト
class fj::FormattedObject : public fj::Object
{
public:
    FormattedObject() = delete;
    FormattedObject(std::unique_ptr<fj::MeshLoader> loader);
    ~FormattedObject() = default;
    
    bool loadFromFile(const std::string& filename);
    
    fj::MeshLoader*const getMeshLoaderPtr();
    
    GLsizeiptr getArrayBufferSize()const;
    
    const GLfloat*const getFrontPtr()const;

private:
    std::unique_ptr<fj::MeshLoader> m_loader;
};

#endif /* formatted_object_hpp */
