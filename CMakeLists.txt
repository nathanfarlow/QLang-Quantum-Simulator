cmake_minimum_required(VERSION 2.8.4)
project(quantum)

set(SOURCE_FILES src/main.cpp src/ofApp.cpp src/ofApp.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_custom_target(quantum COMMAND make -C ${quantum_SOURCE_DIR})
