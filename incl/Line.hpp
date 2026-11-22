#pragma once
#include "incl/Shape.hpp"
#include "incl/Point.hpp"
#include <string>

class Line : public Shape {
private:
    Point start_;
    Point end_;
public:
    explicit Line(size_t id = 0) : Shape(id) {}
    Line(Point start, Point end) : start_(start), end_(end) {}
    std::string getName() const override;
    void draw() const override;
};