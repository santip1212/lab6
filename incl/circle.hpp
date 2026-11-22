#pragma once
#include"incl/Shape.hpp"
#include<fmt/core.h>
#include<string>
class circle : public Shape
{
public:
    explicit circle(size_t id = 0) : Shape(id) {}
    std::string getName() const override;
    void draw() const override;
};