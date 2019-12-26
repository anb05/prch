#include "projectdialog.hpp"

#include "ui_projectdialog.h"

namespace prch {

ProjectDialog::ProjectDialog(QWidget *parent)
    : QDialog(parent)
	, _pProjectDialog (new Ui::ProjectDialog)
{
	_pProjectDialog->setupUi(this);
}

ProjectDialog::~ProjectDialog()
{
	delete _pProjectDialog;
}


void ProjectDialog::onLeftButtonClicked()
{

}

void ProjectDialog::onRightButtonClicked()
{

}

//void ProjectDialog::moveCurrentItem(ProjectListWidget* source,
//									ProjectListWidget* target)
//{

//}

} // namespace prch

