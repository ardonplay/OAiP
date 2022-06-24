cmake_minimum_required(VERSION 3.22)
project(Graphics)

set(CMAKE_CXX_STANDARD 17)

add_executable(Graphics main.cpp graphics.cpp graphics.h)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Graphics sfml-system sfml-window sfml-graphics sfml-audio sfml-network)