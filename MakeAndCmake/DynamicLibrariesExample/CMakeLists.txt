# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.27.4)

# Define the project name
project(testdynamiclib)

# Set the installation prefix to a relative path
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/../../install")

# Find the installed library (dynamic)
find_library(MYLIB_LIBRARY mylib PATHS ${CMAKE_INSTALL_PREFIX}/lib)

# Find the include directory for adder.hpp
find_path(MYLIB_INCLUDE_DIR adder.hpp PATHS ${CMAKE_INSTALL_PREFIX}/include)

# Find the mylib.dll in the bin folder
find_path(MYLIB_DLL_PATH mylib.dll PATHS ${CMAKE_INSTALL_PREFIX}/bin)

# Include the directory where your headers are located
include_directories(${MYLIB_INCLUDE_DIR})

# Create an executable for your main.cpp file
add_executable(testdynamiclib main.cpp)

# Link the installed library to your executable
target_link_libraries(testdynamiclib ${MYLIB_LIBRARY})

# Copy the mylib.dll to the output directory (next to the executable)
add_custom_command(TARGET testdynamiclib POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${MYLIB_DLL_PATH}/mylib.dll $<TARGET_FILE_DIR:testdynamiclib>)