cmake_minimum_required(VERSION 3.5)
project(GridSolver)
message(STATUS ">>> Project Name: " ${PROJECT_NAME})
message(STATUS ">>> Current Source Dir: " ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory (SharedLib)
add_subdirectory (PyModule)
add_subdirectory (CppDemo)
