# My Static Library Example

This repository demonstrates how to create and use a static library in C++ using CMake.

## Directory Structure

```
C:.
└── LearningCpp
    ├── install
    │   ├── include
    │   │   └── adder.hpp               # Header file for the library
    │   └── lib
    │       └── mylib.lib               # Compiled library
    └── MakeAndCmake
        └── StaticLibrariesExample
            ├── CMakeLists.txt          # CMake configuration for the test project
            ├── main.cpp                # Main program file
            ├── build                   # Build directory for compiled files
            └── Adder
                ├── CMakeLists.txt      # CMake configuration for the library project
                ├── adder.cpp           # Implementation of the library functions
                ├── adder.hpp           # Header file for the library
                └── build               # Build directory for compiled files
```

## Build and Install Steps

1. **Navigate to the Library Build Directory**:
   ```bash
   cd C:/LearningCpp/MakeAndCmake/StaticLibrariesExample/Adder/build
2. **Configure, Build, and Install the Library: You can configure the CMake installation, build the library, and install it all in one step**:
    #### For Windows
    ```bash
    cmake -DCMAKE_INSTALL_PREFIX=C:/LearningCpp/install ..; cmake --build . --config Release; cmake --install .
    ```
    #### For Linux
    ```bash
    cmake -DCMAKE_INSTALL_PREFIX=/path/to/install .. && cmake --build . --config Release && cmake --install .
    ```
## Build the Test Project
1. **Navigate to the Test Project Build Directory**:
   ```bash
    cd C:/LearningCpp/MakeAndCmake/StaticLibrariesExample/build
    ```
2. **Configure CMake for the Test Project and Build the Test Project: Set up the project to find the installed library, compile the test project**:
    #### For Windows
    ```bash
    cmake ..; cmake --build . --config Release
    ```
    #### For Linux
    ```bash
    cmake .. && cmake --build . --config Release
    ```
4. **Run the Executable: Navigate to the Release directory and run the test executable**:
    ```bash
    cd C:/LearningCpp/MakeAndCmake/StaticLibrariesExample/build/Release
    .\teststaticlib.exe
    ```