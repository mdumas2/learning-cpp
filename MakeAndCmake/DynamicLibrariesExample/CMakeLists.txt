# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.27.4)

# Define the project name
project(testdynamiclib)

# Set the installation prefix to a relative path
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/../../install")

message(STATUS "CMAKE_INSTALL_PREFIX is set to: ${CMAKE_INSTALL_PREFIX}")

# Find the installed library (dynamic)
find_library(MYLIB_LIBRARY mylib PATHS ${CMAKE_INSTALL_PREFIX}/lib)
message(STATUS "MYLIB_LIBRARY is set to: ${MYLIB_LIBRARY}")

# Find the include directory for adder.hpp
find_path(MYLIB_INCLUDE_DIR adder.hpp PATHS ${CMAKE_INSTALL_PREFIX}/include)
message(STATUS "MYLIB_INCLUDE_DIR is set to: ${MYLIB_INCLUDE_DIR}")

# Include the directory where your headers are located
include_directories(${MYLIB_INCLUDE_DIR})

# Create an executable for your main.cpp file
add_executable(testdynamiclib main.cpp)

# Link the installed library to your executable
target_link_libraries(testdynamiclib ${MYLIB_LIBRARY})
