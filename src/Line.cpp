#include "incl/Line.hpp"
#include <fmt/core.h>

std::string Line::getName() const {
    return "Линия";
}

void Line::draw() const {
    fmt::print("Отрисовка линии\n");
}