#ifndef PROJECTDIALOG_HPP
#define PROJECTDIALOG_HPP

#include <QDialog>

class ProjectListWidget;

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
};

} // namespace prch

#endif // PROJECTDIALOG_HPP
