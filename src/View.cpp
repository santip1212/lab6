#include "incl/View.hpp"
#include <fmt/core.h>

void consolViwe::ShowMessage(const std::string& msg) {
    fmt::print("Информация: {}\n", msg);
}

void consolViwe::ShowError(const std::string& error) {
    fmt::print("Ошибка: {}\n", error);
}

void consolViwe::ShowShapeAdd(const std::string& name) {
    fmt::print("Добавлена фигура: {}\n", name);
}

void consolViwe::ShowShapeDelete(const std::string& name) {
    fmt::print("Удалена фигура: {}\n", name);
}

void consolViwe::ShowDocumentExport(const std::string& filename) {
    fmt::print("Документ экспортирован в: {}\n", filename);
}

void consolViwe::showDocumentImported(const std::string& filename, int Shapeecount) {
    fmt::print("Импортировано {} фигур из файла: {}\n", Shapeecount, filename);
}