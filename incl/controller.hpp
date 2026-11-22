#pragma once 
#include "incl/circle.hpp"
#include "incl/document.hpp"
#include "incl/square.hpp"
#include "incl/View.hpp"
#include "incl/ICommand.hpp"
#include <memory>
#include <string>

class controller {
private:
    std::unique_ptr<document> Document_;
    std::unique_ptr<View> view_;
public:
    explicit controller(std::unique_ptr<View> viVe);
    void newDoc(int id);
    
    void addShape(std::unique_ptr<Shape> shape);
    void deleteShape(size_t shapeId); 
    
    void importDocument(const std::string& file);
    void exportDoc(const std::string& name);
};