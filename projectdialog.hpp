#ifndef PROJECTDIALOG_HPP
#define PROJECTDIALOG_HPP

#include <QDialog>

namespace Ui {
class ProjectDialog;
} // namespace Ui

namespace prch {
class ProjectListWidget;
} // namespace prch

class QAction;

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

public slots:
    void onLeftButtonClicked();
    void onRightButtonClicked();

private:
    void moveCurrentItem(ProjectListWidget* source,
                         ProjectListWidget* target);

private:
    Ui::ProjectDialog* _pProjectDialog ;
};

} // namespace prch

#endif // PROJECTDIALOG_HPP
