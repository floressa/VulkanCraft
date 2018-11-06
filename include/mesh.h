#ifndef MESH_H
#define MESH_H
#pragma once

#include <string>
#include <vector>

#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>

struct Vertex;

class Mesh
{
public:
    Mesh(std::string inPath) : path(inPath) {}

    void loadModelFromFile(std::string path);
    
    uint32_t getVertexCount() { return vertices.size(); }
    uint32_t getIndexCount() { return indices.size(); }

private:
    std::string path;
    
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;

    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;
    
    void extractVertexData();
};

#endif