@startuml
top to bottom direction
hide circle
skinparam classAttributeIconSize 0
skinparam linetype ortho
skinparam nodesep 20
skinparam ranksep 40

interface ICommand {
  + execute() : void
  + undo() : void
}

interface IRenderer {
  + drawShape(shape: Shape&) : void
}

abstract class Shape {
  # id_ : size_t
  + Shape(id: size_t)
  + getId() : size_t
  + draw(renderer: IRenderer&) : void {abstract}
  + getName() : std::string {abstract}
}

struct Point {
  + x : double
  + y : double
}

struct Style {
  + strokeColor : std::string
  + lineWidth : double
  + fillColor : std::string
}

class Circle {
  + Circle(id: size_t)
  + draw(renderer: IRenderer&) : void
  + getName() : std::string
}

class Square {
  + Square(id: size_t)
  + draw(renderer: IRenderer&) : void
  + getName() : std::string
}

class Line {
  - start_ : Point
  - end_ : Point
  + Line(id: size_t, start: Point, end: Point)
  + draw(renderer: IRenderer&) : void
  + getName() : std::string
}

class CompositeShape {
  - children_ : std::vector<std::unique_ptr<Shape>>
  + add(shape: std::unique_ptr<Shape>) : void
  + draw(renderer: IRenderer&) : void
  + getName() : std::string
}

class Document {
  - id_ : int
  - shapes_ : std::vector<std::unique_ptr<Shape>>
  + Document(id: int)
  + addShape(shape: std::unique_ptr<Shape>) : void
  + removeShapeById(id: size_t) : bool
}

class Controller {
  - Document_ : std::unique_ptr<Document>
  - view_ : std::unique_ptr<View>
  + Controller(view: std::unique_ptr<View>)
  + addShape(shape: std::unique_ptr<Shape>) : void
  + deleteShape(id: size_t) : void
}

interface View {
  + ShowMessage(msg: std::string) : void
}

class AddShapeCommand {
  - doc_ : Document&
  - shape_ : std::unique_ptr<Shape>
  + execute() : void
  + undo() : void
}

Controller -[hidden]down-> Document
Document -[hidden]down-> AddShapeCommand
IRenderer -[hidden]down-> Shape
Shape -[hidden]down-> Circle
Point -[hidden]right-> Style

Shape .up.> IRenderer : использует >
Shape <|-- Circle
Shape <|-- Square
Shape <|-- Line
Shape <|-- CompositeShape

CompositeShape o-down-> Shape : содержит >
ICommand <|.. AddShapeCommand
AddShapeCommand -down-> Document : изменяет >
Controller -down-> Document : управляет >
Controller -down-> View : обновляет >
Controller .down.> ICommand : создает >
Line *-down-> Point : использует >
Shape .down.> Style : имеет >

@enduml

Текстовая диаграмма классов, построение осуществялось с помощью plantuml.com
