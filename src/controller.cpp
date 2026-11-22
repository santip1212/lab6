#include"incl/controller.hpp"
#include "incl/AddShapeCommand.hpp"
#include "incl/RemoveShapeCommand.hpp" 
#include <fmt/core.h>

controller::controller(std::unique_ptr<View> viVe) : view_(std::move(viVe)){}

void controller::newDoc(int id){
    Document_ = std::make_unique<document>(id);
    view_->ShowMessage("Создан новый документ с ID: " + std::to_string(id));
}

void controller::addShape(std::unique_ptr<Shape> shape) {
    if (!Document_) {
        view_->ShowError("Ошибка: Документ не создан!");
        return;
    }
    std::string name = shape->getName();
    auto cmd = std::make_unique<AddShapeCommand>(*Document_, std::move(shape));
    cmd->execute(); 
    
    view_->ShowShapeAdd(name); 
}

void controller::deleteShape(size_t shapeId) {
    if (!Document_) {
        view_->ShowError("Ошибка: Документ не создан!");
        return;
    }
    auto cmd = std::make_unique<RemoveShapeCommand>(*Document_, shapeId);
    cmd->execute();
    
    view_->ShowShapeDelete(std::to_string(shapeId));
}

void controller::exportDoc(const std::string& name) {
    if (Document_) {
        Document_->exportDocument(name);
        view_->ShowDocumentExport(name);
    } else {
        view_->ShowError("Ошибка: Нет доступных документов для экспорта!");
    }
}

void controller::importDocument(const std::string& file) {
    if (Document_) {
        int importedCount = 0;
        if (Document_->importDocument(file, importedCount)) {
            view_->showDocumentImported(file, importedCount);
        } else {
            view_->ShowError("Ошибка: Не удалось импортировать документ из файла: " + file);
        }
    } else {
        view_->ShowError("Ошибка: Документ не создан!");
    }
}