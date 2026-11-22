#pragma once
#include "incl/ICommand.hpp"
#include "incl/document.hpp"
#include "incl/Point.hpp"

class MoveShapeCommand : public ICommand {
private:
    document& doc_;
    size_t shapeId_;
    Point newPos_;
public:
    MoveShapeCommand(document& doc, size_t shapeId, Point newPos) 
        : doc_(doc), shapeId_(shapeId), newPos_(newPos) {}

    void execute() override;
    void undo() override;
};