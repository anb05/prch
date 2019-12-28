#include "projectdialog.hpp"

#include "ui_projectdialog.h"

#include <QToolButton>

namespace prch {

ProjectDialog::ProjectDialog(QWidget *parent)
    : QDialog(parent)
    , _pProjectDialog (new Ui::ProjectDialog)
{
    _pProjectDialog->setupUi(this);

    _pProjectDialog->_projectA->addItem("Giosue Carducci");
    _pProjectDialog->_projectA->addItem("Eyvind Johnson");
    _pProjectDialog->_projectA->addItem("Sally Prudhomme");
    _pProjectDialog->_projectA->addItem("Henryk Sienkiewicz");
    _pProjectDialog->_projectA->addItem("Carl Spitteler");
    _pProjectDialog->_projectA->addItem("Rabindranath Tagore");
    _pProjectDialog->_projectA->addItem("Kawabata Yasunari");

    _pProjectDialog->_projectB->addItem("Rudolf Eucken");
    _pProjectDialog->_projectB->addItem("Anatole France");
    _pProjectDialog->_projectB->addItem("Rudyard Kipling");
    _pProjectDialog->_projectB->addItem("Thomas Mann");
    _pProjectDialog->_projectB->addItem("Eugene O'Neill");
    _pProjectDialog->_projectB->addItem("Sigrid Undset");

    connect(_pProjectDialog->_leftBtn, &QToolButton::clicked,
            this,                      &ProjectDialog::onLeftButtonClicked);

    connect(_pProjectDialog->_rightBtn, &QToolButton::clicked,
            this,                       &ProjectDialog::onRightButtonClicked);
}

ProjectDialog::~ProjectDialog()
{
    delete _pProjectDialog;
}


void ProjectDialog::onLeftButtonClicked()
{
    moveCurrentItem(_pProjectDialog->_projectB,
                    _pProjectDialog->_projectA);
}

void ProjectDialog::onRightButtonClicked()
{
    moveCurrentItem(_pProjectDialog->_projectA,
                    _pProjectDialog->_projectB);
}

void ProjectDialog::moveCurrentItem(ProjectListWidget* source,
                                    ProjectListWidget* target)
{
    if (source->currentItem()) {
        QListWidgetItem *newItem = source->currentItem()->clone();
        target->addItem(newItem);
        target->setCurrentItem(newItem);
        delete source->currentItem();
    }
}

} // namespace prch

