cmake_minimum_required (VERSION 2.8.8)
project (project_name)
set (PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set (INCLUDE ${PROJECT_ROOT}/../include/)
include_directories (${INCLUDE})
add_definitions ("-std=c++11 -Wall -pedantic-errors -Wconversion")

add_executable (main main.cpp)
