cmake_minimum_required(VERSION 3.28)
project(physcissimulator LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(main src/main.cpp)


set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)

