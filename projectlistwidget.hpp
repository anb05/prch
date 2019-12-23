#ifndef PROJECTLISTWIDGET_HPP
#define PROJECTLISTWIDGET_HPP

#include <QListWidget>
#include <QPoint>

class QMouseEvent;
class QDragEnterEvent;
class QDragMoveEvent;
class QDropEvent;

namespace prch {

class ProjectListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit ProjectListWidget(QWidget* parent = nullptr);
    ~ProjectListWidget() override;

    explicit ProjectListWidget(const ProjectListWidget& ) = delete;
    explicit ProjectListWidget(ProjectListWidget&& )      = delete;

public:
    ProjectListWidget& operator= (const ProjectListWidget& ) = delete;
    ProjectListWidget& operator= (ProjectListWidget&& )      = delete;

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dragMoveEvent(QDragMoveEvent* event) override;
    void dropEvent(QDropEvent* event) override;

private:
    void performDrag();

private:
	QPoint _startPos;
};

} // namespace prch

#endif // PROJECTLISTWIDGET_HPP
