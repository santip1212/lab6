#include "incl/CompositeShape.hpp"
#include <fmt/core.h>

std::string CompositeShape::getName() const {
    return "Группа фигур";
}

void CompositeShape::draw() const {
    fmt::print("Отрисовка группы фигур ({} элементов):\n", children_.size());
    for (const auto& child : children_) {
        child->draw();
    }
}