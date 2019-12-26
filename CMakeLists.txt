cmake_minimum_required(VERSION 3.5)

set(PR_NAME projChooser)

project(${PR_NAME} VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(HEADERS
    application.hpp
    projectdialog.hpp
    projectlistwidget.hpp
    )

set(SRC
    application.cpp
    main.cpp
    projectdialog.cpp
    projectlistwidget.cpp
    )

set(ASSETS
    assets.qrc
    )

set(FORMS
	projectdialog.ui
	)

add_executable(${PR_NAME} ${FORMS} ${HEADERS} ${SRC} ${ASSETS})

target_link_libraries(${PR_NAME} PRIVATE Qt5::Widgets)
