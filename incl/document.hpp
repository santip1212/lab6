#pragma once 
#include"incl/Shape.hpp"
#include<fmt/core.h>
#include<memory>
#include<vector>
#include<string>

class document
{
private:
    int id_;
    std::vector<std::unique_ptr<Shape>> Shape_;
public:
    int getId()const;
    explicit document(int id);
    void addShape(std::unique_ptr<Shape> Shape);
    bool removeShapeById(size_t shapeId);
    bool importDocument(const std::string& file, int& importedCount);
    void exportDocument(const std::string &file);
}; 
