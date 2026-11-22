#include "incl/circle.hpp"
#include "incl/square.hpp"
#include "incl/Line.hpp"
#include "incl/CompositeShape.hpp"
#include "incl/controller.hpp"
#include "incl/View.hpp"
#include <memory>
#include <iostream>

std::unique_ptr<controller> app;
size_t nextId = 1; // Счетчик ID для фигур

void buttonCreateDoc(int id) {
    app->newDoc(id);
}

void buttonAddShape(std::unique_ptr<Shape> shape) {
    app->addShape(std::move(shape));
}

int main(int, char**) {
    app = std::make_unique<controller>(std::make_unique<consolViwe>());
    
    buttonCreateDoc(1);
    
    app->addShape(std::make_unique<circle>(1));
    app->addShape(std::make_unique<square>(2));
    
    app->deleteShape(2); 

    return 0;
}