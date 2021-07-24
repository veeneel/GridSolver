cmake_minimum_required(VERSION 3.5)
project(CppDemo)
message(STATUS ">>> Project Name: " ${PROJECT_NAME})
message(STATUS ">>> Current Source Dir: " ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE SolverDemo.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} LINK_PUBLIC SharedLib)
#TARGET_LINK_LIBRARIES(${LIBNAME} ${Boost_LIBRARIES} -lpython2.7 -fPIC -shared)
