cmake_minimum_required(VERSION 3.14)

project(QTcpServerThreaded LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network)

add_executable(QTcpServerThreaded
  main.cpp
  server.h
  server.cpp
  worker.h
  worker.cpp
)
target_link_libraries(QTcpServerThreaded Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network)

install(TARGETS QTcpServerThreaded
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
