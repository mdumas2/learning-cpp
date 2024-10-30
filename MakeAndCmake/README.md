# Make and CMake

A Makefile is a file used by the make build automation tool to control the build process for projects, typically in C, C++, or other programming languages. It contains rules and instructions on how to compile and link a program, specifying the dependencies between files and the commands needed to produce executable output.

CMake is a tool that generates build files, such as Makefiles, for different platforms and build systems. CMake helps manage the build process for complex software projects in a more portable and cross-platform way by abstracting the underlying build system.

CMake uses a file called CMakeLists.txt to define the project structure, dependencies, and build instructions. Based on this file, CMake generates platform-specific build files, such as:

- Makefiles (for Unix-like systems such as Linux and macOS)
- Visual Studio project files (for Windows)
- Xcode project files (for macOS)

## Prerequisites

- **CMake**: Ensure that CMake is installed on your system. You can download it from [CMake's official website](https://cmake.org/download/).
- **MinGW**: Make sure you have MinGW installed for building your project on Windows.

## Example Hello Cmake:

For detailed instructions on building with Make and Cmake, please refer to the [Hello Cmake Example Documentation](./HelloCmakeExample/README.md).

## Build And Link Static Libraries

For detailed instructions on building static libraries, please refer to the [Build Static Libraries Documentation](./StaticLibrariesExample/README.md).

## Build And Link Dynamic Libraries

For detailed instructions on building dynamic libraries, please refer to the [Build Dynamic Libraries Documentation](./DynamicLibrariesExample/README.md).

# GIT Submodules with CMake

For detailed instructions on using GIT Submodules, please refer to the [Git Submodules Documentation](./GitSubModuleExample/README.md).
