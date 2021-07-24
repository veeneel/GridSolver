cmake_minimum_required(VERSION 3.5)
project(SharedLib)
message(STATUS ">>> Project Name: " ${PROJECT_NAME})
message(
    STATUS
    ">>> Current Source Dir: "
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Add a shared library
set(SOURCE SharedLib.cpp)
add_library(${PROJECT_NAME} SHARED ${SOURCE})

# Set up the libraries and header search paths
target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

