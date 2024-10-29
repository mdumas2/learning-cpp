# Make and CMake

A Makefile is a file used by the make build automation tool to control the build process for projects, typically in C, C++, or other programming languages. It contains rules and instructions on how to compile and link a program, specifying the dependencies between files and the commands needed to produce executable output.

CMake is a tool that generates build files, such as Makefiles, for different platforms and build systems. CMake helps manage the build process for complex software projects in a more portable and cross-platform way by abstracting the underlying build system.

CMake uses a file called CMakeLists.txt to define the project structure, dependencies, and build instructions. Based on this file, CMake generates platform-specific build files, such as:

Makefiles (for Unix-like systems such as Linux and macOS)
Visual Studio project files (for Windows)
Xcode project files (for macOS)

main.cpp:
    #include <iostream>
    int main ()
    {
        std::cout << "Hello" << std::endl;
        return 0;
    }

make
makefile:
    default:
        g++ main.cpp -o out

mkdir out/build
cmake -S . -B out/build/
CMakeLists.txt:
    cmake_minimum_required(VERSION 3.10.2)
    
    project(Hello)

    add_executable(${PROJECT_NAME} main.cpp)

# Libraries
install makes the .exe accesible by the whole system so i dont need to do cd into the release directorie

sudo make install
CMakeLists.txt:
    cmake_minimum_required(VERSION 2.8)
    project(Hello)
    add_executable(${PROJECT_NAME} main.cpp)
    install(TARGETS ${PROJECT_NAME} DESTINATION bin)

## Build static libraries
mkdir SomeLibDemo
mkdir cpp
cd cpp 
ls

adder.h:

    #pragma once
    // Declare functions
    namespace mylib
    {
        int add(int a, int b);
        float add(float a, float b);
    }

adder.cpp:

    #include "adder.h"
    
    int mylib::add(int a, int b)
    {
        return (a + b);
    }

    float mylib::add(float a, float b)
    {
        return (a + b);
    }

CMakeLists.txt:

    cmake_minimum_required(VERSION 2.8)
    project(mylib)
    add_library(mylib adder.cpp)

mkdir build/
cd build/
cmake -S .. 
make

this generate libmylib.a (.a os the same as .lib in windows)

### Now how to use it?

main.cpp:

    #include <iostream>
    #include "../../SomeLibDemo/cpp/adder.h"
    int main ()
    {
        return mylib::add(2, 3);
    }

CMakeLists.txt:

    cmake_minimum_required(VERSION 3.13)
    project(teststaticlib)
    add_library(teststaticlib main.cpp)
    target_link_directories(teststaticlib PRIVATE ${CMAKE_SOURCE_DIR}/../../SomeLibDemo/cpp/build/)
    target_link_libraries(teststaticlib libmylib)

#### How to add the include directories into cmake?

Library CMakeLists.txt:

    cmake_minimum_required(VERSION 3.27.4)
    project(mylib)
    add_library(mylib adder.cpp)
    set_target_properties(mylib PROPERTIES PUBLIC_HEADER adder.h)
    install(TARGETS mylib LIBRARY DESTINATION lib
            PUBLIC_HEADER DESTINATION include
            )

Run: sudo make install

Main CMakeLists.txt:

    cmake_minimum_required(VERSION 3.27.4)
    project(teststaticlib)
    add_library(teststaticlib main.cpp)
    target_link_libraries(teststaticlib libmylib)

main.cpp:

    #include <iostream>
    #include "adder.h"
    int main ()
    {
        return mylib::add(2, 3);
    }

## build dynamic libraries

#### How to use them?

# GIT Submodules with CMAKE
