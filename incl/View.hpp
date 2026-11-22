#pragma once
#include<string>
#include<fmt/core.h>

class View
{
public:
    virtual ~View() = default;
    virtual void ShowMessage(const std::string& massage ) = 0;
    virtual void ShowError(const std::string& error) = 0;
    virtual void ShowShapeAdd(const std::string& name) = 0;
    virtual void ShowShapeDelete(const std::string& name) = 0;
    virtual void ShowDocumentExport(const std::string& filename) = 0;
    virtual void showDocumentImported(const std::string& filename, int Shapeecount) = 0;
};

class consolViwe : public View{
public:
     void ShowMessage(const std::string& massage ) override;
     void ShowError(const std::string& error) override;
     void ShowShapeAdd(const std::string& name) override;
     void ShowShapeDelete(const std::string& name) override;
     void ShowDocumentExport(const std::string& filename) override;
     void showDocumentImported(const std::string& filename, int Shapeecount) override;

};

