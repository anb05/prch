#include "projectdialog.hpp"
#include "application.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    prch::Application app(argc, argv);
    prch::ProjectDialog win;
    win.show();
    return app.exec();
}
