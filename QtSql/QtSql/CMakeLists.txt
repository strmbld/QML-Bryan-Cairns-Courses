cmake_minimum_required(VERSION 3.14)

project(QtSql LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Sql)

add_executable(QtSql
  main.cpp
  user.h
  user.cpp
)
target_link_libraries(QtSql Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Sql)

install(TARGETS QtSql
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
