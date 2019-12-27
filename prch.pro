QT       = core gui widgets
TEMPLATE = app
TARGET   = PRCH
#INCLUDEPATH += .
CONFIG      += c++14

SOURCES   +=                       \
             application.cpp       \
             main.cpp              \
             projectdialog.cpp     \
             projectlistwidget.cpp

HEADERS   +=                       \
             application.hpp       \
             projectdialog.hpp     \
             projectlistwidget.hpp

RESOURCES +=                       \
             assets.qrc

FORMS     +=                       \
             projectdialog.ui

