cmake_minimum_required(VERSION 3.14)

project(QtJSONSerialization LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(QtJSONSerialization
  main.cpp
  converter.h
  converter.cpp
  someclass.h
  someclass.cpp
)
target_link_libraries(QtJSONSerialization Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS QtJSONSerialization
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
