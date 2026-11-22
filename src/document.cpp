#include"incl/document.hpp"
#include"incl/circle.hpp"
#include"incl/square.hpp"
#include<fmt/core.h>
#include<memory>
#include<string>

document::document(int id) : id_(id) {}

int document::getId() const {
    return id_;
}

void document::addShape(std::unique_ptr<Shape> Shape) {
    Shape_.push_back(std::move(Shape));
}

bool document::removeShapeById(size_t shapeId) {
    for (auto it = Shape_.begin(); it != Shape_.end(); ++it) {
        if ((*it)->getId() == shapeId) {
            Shape_.erase(it);
            return true;
        }
    }
    return false;
}

void document::exportDocument(const std::string &file) {
}

bool document::importDocument(const std::string& file, int& importedCount) {
    
    Shape_.push_back(std::make_unique<circle>());
    Shape_.push_back(std::make_unique<square>());
    Shape_.push_back(std::make_unique<circle>());
    
    importedCount = 3;  
    return true;  
}