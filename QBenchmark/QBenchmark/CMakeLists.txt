cmake_minimum_required(VERSION 3.14)

project(QBenchmark LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Test)

add_executable(QBenchmark
  main.cpp
  widget.h
  widget.cpp
)
target_link_libraries(QBenchmark Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Test)

install(TARGETS QBenchmark
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
