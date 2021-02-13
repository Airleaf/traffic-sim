cmake_minimum_required(VERSION 3.10)

project(traffic-sim-tests)

include_directories(./include)

file(GLOB SOURCES "./src/*.cpp" "./src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES} main.cpp)

target_link_libraries(traffic-sim-tests sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
