# Make and CMake

A Makefile is a file used by the make build automation tool to control the build process for projects, typically in C, C++, or other programming languages. It contains rules and instructions on how to compile and link a program, specifying the dependencies between files and the commands needed to produce executable output.

CMake is a tool that generates build files, such as Makefiles, for different platforms and build systems. CMake helps manage the build process for complex software projects in a more portable and cross-platform way by abstracting the underlying build system.

CMake uses a file called CMakeLists.txt to define the project structure, dependencies, and build instructions. Based on this file, CMake generates platform-specific build files, such as:

- Makefiles (for Unix-like systems such as Linux and macOS)
- Visual Studio project files (for Windows)
- Xcode project files (for macOS)

## Example:

**main.cpp**:
```c
#include <iostream>
int main ()
{
    std::cout << "Hello" << std::endl;
    return 0;
}
```

**makefile**:
```makefile
default:
    g++ main.cpp -o out
```

**CMakeLists.txt**:
```cmake
cmake_minimum_required(VERSION 3.27.4)

project(Hello)

add_executable(${PROJECT_NAME} main.cpp)
```

## Build Static Libraries

For detailed instructions on building static libraries, please refer to the [Build Static Libraries Documentation](./StaticLibrariesExample/README.md).

## Build Dynamic Libraries

For detailed instructions on building dynamic libraries, please refer to the [Build Dynamic Libraries Documentation](./DynamicLibrariesExample/README.md).

# GIT Submodules with CMAKE
