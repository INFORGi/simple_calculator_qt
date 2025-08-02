cmake_minimum_required(VERSION 3.15)
project(test_qt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(test_qt main.cpp calculator.cpp) 

target_link_libraries(test_qt PRIVATE Qt5::Widgets)
