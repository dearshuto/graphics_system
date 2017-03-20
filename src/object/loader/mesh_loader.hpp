//
//  mesh_loader.hpp
//  OpenGL
//
//  Created by Shuto on 2017/03/20.
//
//

#ifndef mesh_loader_hpp
#define mesh_loader_hpp

#include <string>
#include <tuple>
#include <vector>
#include "utility/OpenGL.h"

namespace fj {
    class MeshLoader;
}

/// メッシュデータをファイルシステムから読み取り, 頂点, 稜線, 法線の情報を取得する.
class fj::MeshLoader
{
public:
    MeshLoader() = default;
    virtual~MeshLoader() = default;
    
    /** @brief
     * @return 読み取りに成功したか. */
    virtual bool loadFromFile(const std::string& filename) = 0;
    
    GLsizeiptr getArrayBufferSize()const;
    
    const GLfloat*const getFrontPtr()const;
    
protected:
    /// 位置(x, y, z), 法線(x, y, z)のように, 位置情報と法線情報の6つが連続してならんでいる
    std::vector<GLfloat> m_vertex_normal;
    
    /// 頂点へのインデックス
    std::vector<GLuint> m_indices;
};

#endif /* mesh_loader_hpp */
