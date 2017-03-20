//
//  wavefront_obj_loader.cpp
//  OpenGL
//
//  Created by Shuto on 2017/03/20.
//
//

#include <iostream>
#include <fstream>
#include "wavefront_obj_loader.hpp"

bool fj::WavefrontObjLoader::loadFromFile(const std::string &filename)
{
    std::ifstream input(filename);
    
    if (input.fail())
    {
        std::cout << filename << " is not found." << std::endl;
        return false;
    }
    

    std::string line = "";
    while (std::getline(input, line))
    {
        std::vector<std::string> list;
        boost::algorithm::split(list, line, boost::is_any_of(" "));
        boost::split(list, line, boost::is_space());
        std::string firstChar = "INIT";
        std::vector<std::string>& list_ref = list;
        
        firstChar = list[0];
        
        if (firstChar == "v") {
            m_modelData.addVertex(list_ref);
        }
        
        if (firstChar == "f") {
            m_modelData.addFace(list_ref);
        }
    }

    return true;
}
