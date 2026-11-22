#pragma once
#include "incl/ICommand.hpp"
#include "incl/document.hpp"
#include "incl/Shape.hpp"
#include <memory>

class AddShapeCommand : public ICommand {
private:
    document& doc_;
    std::unique_ptr<Shape> shape_;
public:
    AddShapeCommand(document& doc, std::unique_ptr<Shape> shape) 
        : doc_(doc), shape_(std::move(shape)) {}

    void execute() override; 
    void undo() override;
};