#ifndef PROJECTDIALOG_HPP
#define PROJECTDIALOG_HPP

#include <QDialog>

namespace prch {

class ProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectDialog(QWidget *parent = nullptr);
    ~ProjectDialog() override;

    explicit ProjectDialog(const ProjectDialog& ) = delete;
    explicit ProjectDialog(ProjectDialog&& )      = delete;

public:
    ProjectDialog& operator= (const ProjectDialog& ) = delete;
    ProjectDialog& operator= (ProjectDialog&& )      = delete;

};

} // namespace prch

#endif // PROJECTDIALOG_HPP
