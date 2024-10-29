cmake_minimum_required(VERSION 3.27.4)
project(teststaticlib)

# Set the installation prefix to a relative path
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/../../install")

# Find the installed library
find_library(MYLIB_LIBRARY mylib PATHS ${CMAKE_INSTALL_PREFIX}/lib)

# Find the include directory for adder.hpp
find_path(MYLIB_INCLUDE_DIR adder.hpp PATHS ${CMAKE_INSTALL_PREFIX}/include)

# Include the directory where your headers are located
include_directories(${MYLIB_INCLUDE_DIR})

# Create an executable for your main.cpp file
add_executable(teststaticlib main.cpp)

# Link the installed library to your executable
target_link_libraries(teststaticlib PRIVATE ${MYLIB_LIBRARY})
