#pragma once
#include "incl/ICommand.hpp"
#include "incl/document.hpp"

class RemoveShapeCommand : public ICommand {
private:
    document& doc_;
    size_t shapeId_;
public:
    RemoveShapeCommand(document& doc, size_t shapeId) 
        : doc_(doc), shapeId_(shapeId) {}

    void execute() override;
    void undo() override;
};