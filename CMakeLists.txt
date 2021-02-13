cmake_minimum_required(VERSION 3.14)
project(traffic)

set(CMAKE_CXX_FLAGS " -std=c++17")

file(GLOB SOURCES "src/*.cpp" "src/*.c")

add_executable(traffic ${SOURCES})

include_directories(/usr/local/include)
include_directories(./include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

target_link_libraries(traffic sfml-system sfml-window sfml-graphics sfml-audio sfml-network)