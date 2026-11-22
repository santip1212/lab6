#pragma once
#include <string>
#include <cstddef> 

class Shape {
protected:
    size_t id_; 
public:
    explicit Shape(size_t id = 0) : id_(id) {}
    virtual ~Shape() = default;
    
    size_t getId() const { return id_; }
    
    virtual std::string getName() const = 0;
    virtual void draw() const = 0;
};