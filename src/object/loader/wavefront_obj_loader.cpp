//
//  wavefront_obj_loader.cpp
//  OpenGL
//
//  Created by Shuto on 2017/03/20.
//
//

#include <array>
#include <iostream>
#include <fstream>
#include <sstream>
#include "wavefront_obj_loader.hpp"

bool fj::WavefrontObjLoader::loadFromFile(const std::string &filename)
{
    std::ifstream input(filename);
    
    if (input.fail())
    {
        std::cout << filename << " is not found." << std::endl;
        return false;
    }
    
    const auto Split = [](const std::string& line, const char delimiter){
        std::vector<std::string> result;
        std::string component = "";
        for (auto& ch: line)
        {
            if (ch == delimiter)
            {
                result.push_back(component);
                component = "";
            }
            else
            {
                component += ch;
            }
        }
        
        if (component != "")
        {
            result.push_back(component);
        }
        
        return result;
    };

    std::vector<std::array<GLfloat, 3>> vertices;
    std::vector<std::array<GLfloat, 3>> normals;
    
    std::string line = "";
    while (std::getline(input, line))
    {
        auto result = Split(line, ' ');
        std::string firstChar = "INIT";
        
        firstChar = result[0];
        
        if (firstChar == "v")
        {
            const GLfloat kX = std::stof(result[1]);
            const GLfloat kY = std::stof(result[2]);
            const GLfloat kZ = std::stof(result[3]);
            vertices.push_back({{kX, kY, kZ}});
        }
        else if(firstChar == "vn")
        {
            const GLfloat kX = std::stof(result[1]);
            const GLfloat kY = std::stof(result[2]);
            const GLfloat kZ = std::stof(result[3]);
            normals.push_back({{kX, kY, kZ}});
        }
        else if (firstChar == "f")
        {
            const auto kV1 = Split(result[1], '/');
            const auto kV2 = Split(result[2], '/');
            const auto kV3 = Split(result[3], '/');
            
            // Wavefront OBJ は1はじまりなので, 0はじまりになるように-1しておく
            const GLuint kI1 = static_cast<GLuint>(std::stoi(kV1[0]) - 1);
            const GLuint kI2 = static_cast<GLuint>(std::stoi(kV2[0]) - 1);
            const GLuint kI3 = static_cast<GLuint>(std::stoi(kV3[0]) - 1);
            
            // ここで法線情報を取得!
            const GLuint kN1 = static_cast<GLuint>(std::stoi(kV1[2]) - 1);
            
            m_indices.push_back(kI1);
            m_indices.push_back(kI2);
            m_indices.push_back(kI3);
        }
    }

    m_vertex_normal.reserve(vertices.size() * 3 *2);
    
    for (auto& vertex : vertices)
    {
        m_vertex_normal.push_back(vertex[0]);
        m_vertex_normal.push_back(vertex[1]);
        m_vertex_normal.push_back(vertex[2]);
        
        // 法線は未実装なので, ダミーをいれておく
        m_vertex_normal.push_back(0);
        m_vertex_normal.push_back(0);
        m_vertex_normal.push_back(0);
    }
    
    return true;
}

GLsizei fj::WavefrontObjLoader::getDrawNum()const
{
    return m_indices.size();
}
