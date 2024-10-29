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


## build dynamic libraries

#### How to use them?

# GIT Submodules with CMAKE
