cmake_minimum_required(VERSION 3.14)

project(app LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(app
  main.cpp
)
add_library(lib STATIC IMPORTED)
#set_property(TARGET ExternalSharedLib PROPERTY
#             IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/lib/ExternalSharedLib.dll")
#set_property(TARGET ExternalSharedLib PROPERTY
#             IMPORTED_IMPLIB "${CMAKE_CURRENT_SOURCE_DIR}/lib/ExternalSharedLib.lib")
set_target_properties(lib PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/lib/lib.lib"
    #IMPORTED_IMPLIB "${CMAKE_CURRENT_SOURCE_DIR}/lib/lib.lib"
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/inc"
)
target_link_libraries(app Qt${QT_VERSION_MAJOR}::Core lib)

install(TARGETS app
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
