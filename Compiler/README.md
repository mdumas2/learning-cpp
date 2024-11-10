# My Dynamic Library Example

This repository demonstrates how to run and use a Make and CMake.

## Directory Structure

```
C:.
└── LearningCpp
    └── MakeAndCmake
        └── HelloCmakeExample
            ├── CMakeLists.txt          # CMake configuration for the test project
            ├── Makefile                # Make File
            ├── main.cpp                # Main program file
            └── build                   # Build directory for compiled files
```

## Build the Test Project
2. **Navigate to the Test Project Build Directory**:
   ```bash
    cd C:/LearningCpp/MakeAndCmake/HelloCmakeExample
    make
    ```
2. **Navigate to the Test Project Build Directory**:
   ```bash
    cd C:/LearningCpp/MakeAndCmake/HelloCmakeExample/build
    ```
3. **Configure CMake for the Test Project and Build the Test Project: Set up the project to find the installed library, compile the test project**:
    #### For Windows
    ```bash
    cmake ..; cmake --build . --config Release
    ```
    #### For Linux
    ```bash
    cmake .. && cmake --build . --config Release
    ```
1. **Run the Executable: Navigate to the Release directory and run the test executable**:
    ```bash
    cd C:/LearningCpp/MakeAndCmake/HelloCmakeExample/build/Release
    .\Hello.exe
    