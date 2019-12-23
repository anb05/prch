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

}

void ProjectListWidget::dragMoveEvent(QDragMoveEvent* event)
{

}

void ProjectListWidget::dropEvent(QDropEvent* event)
{

}

void ProjectListWidget::performDrag()
{
	QListWidgetItem* item = currentItem();

	if (item) {
		QMimeData* mimeData = new QMimeData;
		mimeData->setText(item->text());

		QDrag* drag = new QDrag(this);
	}
}

} // namespace prch
