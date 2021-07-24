cmake_minimum_required(VERSION 3.5)
project(PyModule)
message(STATUS ">>> Project Name: " ${PROJECT_NAME})
message(
    STATUS
    ">>> Current Source Dir: "
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Find python and Boost - both are required dependencies
find_package(PythonLibs 3.6 REQUIRED)
message(STATUS "PYTHON_INCLUDE_DIRS =" "${PYTHON_INCLUDE_DIRS}")
message(STATUS "PYTHON_LIBRARIES = " "${PYTHON_LIBRARIES}")

#set(_Boost_NUMPY_DEPENDENCIES python3.6)
find_package(Boost 1.65 REQUIRED COMPONENTS python)
set(BOOST_PYTHON_LIBRARY "boost_python")
#find_package(Boost 1.65 REQUIRED COMPONENTS python numpy)
#set(BOOST_PYTHON_LIBRARY "boost_python" "boost_numpy3")
message(STATUS "BOOST_PYTHON_LIBRARY = " "${BOOST_PYTHON_LIBRARY}")

option(WITH_BOOST_PYTHON "Build With Boost.Python" ON)
if (WITH_BOOST_PYTHON)
   add_definitions(-DWITH_BOOST_PYTHON)
endif()

# Without this, any build libraries automatically have names "lib{x}.so"
set(CMAKE_SHARED_MODULE_PREFIX "")

# Add a shared module - modules are intended to be imported at runtime.
# - This is where you add the source files
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../SolverLib/)
set(SOURCE "SharedLib.cpp")
message(STATUS ">>> SOURCE =" "${SOURCE}")
add_library(${PROJECT_NAME} MODULE ${SOURCE})

# Set up the libraries and header search paths for this target
target_link_libraries(
    ${PROJECT_NAME}
    ${PYTHON_LIBRARIES}
    ${BOOST_PYTHON_LIBRARY}
)
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${PYTHON_INCLUDE_DIRS}
)
# target_include_directories
# (
#     ${PROJECT_NAME}
#     PUBLIC
#     ${CMAKE_CURRENT_SOURCE_DIR}
# )

