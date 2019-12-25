#include "projectlistwidget.hpp"

#include <QApplication>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QListWidgetItem>
#include <QMimeData>
#include <QDrag>

namespace prch {

ProjectListWidget::ProjectListWidget(QWidget* parent)
    : QListWidget(parent)
{
    setAcceptDrops(true);
}

ProjectListWidget::~ProjectListWidget()
{}

void ProjectListWidget::mousePressEvent(QMouseEvent* event)
{
    if (Qt::LeftButton == event->button()) {
        _startPos = event->pos();
    }

    QListWidget::mousePressEvent(event);
}

void ProjectListWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton) {
        int distance = (event->pos() - _startPos).manhattanLength();

        if (QApplication::startDragDistance() < distance) {
            performDrag();
        }
    }

    QListWidget::mouseMoveEvent(event);
}

void ProjectListWidget::dragEnterEvent(QDragEnterEvent* event)
{
    ProjectListWidget* soure = qobject_cast<ProjectListWidget*>(event->source());

    if (soure && (soure != this)) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void ProjectListWidget::dragMoveEvent(QDragMoveEvent* event)
{
    ProjectListWidget* soure = qobject_cast<ProjectListWidget*>(event->source());

    if (soure && (soure != this)) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void ProjectListWidget::dropEvent(QDropEvent* event)
{
    ProjectListWidget* source = qobject_cast<ProjectListWidget*>(event->source());

    if (source && (source != this)) {
        addItem(event->mimeData()->text());
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void ProjectListWidget::performDrag()
{
    QListWidgetItem* item = currentItem();

    if (!item) {
        return;
    }

    QMimeData* mimeData = new QMimeData;
    mimeData->setText(item->text());

    QDrag* drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(QPixmap(":/img/person"));

    if (drag->exec(Qt::MoveAction) == Qt::MoveAction)
        delete item;
}

} // namespace prch
