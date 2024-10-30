# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.27.4)

# Define the project name
project(mylib)

# Create a library target named 'mylib' as a shared library from the source file 'adder.cpp'
add_library(mylib SHARED adder.cpp)

# Set properties for the target 'mylib'
# Specify that 'adder.hpp' should be treated as a public header
set_target_properties(mylib PROPERTIES PUBLIC_HEADER adder.hpp)

# Ensure all symbols are exported on Windows
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Install the target 'mylib'
# - LIBRARY: Install the compiled library to the specified destination
# - PUBLIC_HEADER: Install the public header file to the specified destination
install(TARGETS mylib 
    LIBRARY DESTINATION lib        # Destination for the dynamic library
    PUBLIC_HEADER DESTINATION include # Destination for the public headers
)
