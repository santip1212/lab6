#pragma once
#include "incl/Shape.hpp"
#include <vector>
#include <memory>
#include <string>

class CompositeShape : public Shape {
private:
    std::vector<std::unique_ptr<Shape>> children_;
public:
    void add(std::unique_ptr<Shape> shape) {
        children_.push_back(std::move(shape));
    }
    
    std::string getName() const override;
    void draw() const override;
};