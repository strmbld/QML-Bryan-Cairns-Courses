cmake_minimum_required(VERSION 3.16)

project(QmlCppIntegration VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Quick)


qt_add_executable(appQmlCppIntegration
    main.cpp
    resources.qrc
    someclass.h
    someclass.cpp
)

qt_add_qml_module(appQmlCppIntegration
    URI QmlCppIntegration
    VERSION 1.0
    QML_FILES Main.qml
)

set_target_properties(appQmlCppIntegration PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appQmlCppIntegration
    PRIVATE Qt6::Quick
)

install(TARGETS appQmlCppIntegration
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
