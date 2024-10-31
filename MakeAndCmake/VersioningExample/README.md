# My Dynamic Library Example

This repository demonstrates how versioning using CMake.

## Directory Structure

```
C:.
└── LearningCpp
    └── MakeAndCmake
        └── VersioningExample
            ├── CMakeLists.txt          # CMake configuration for the test project
            ├── main.cpp                # Main program file
            └── build                   # Build directory for compiled files
```

## Build the Test Project
1. **Navigate to the Test Project Build Directory**:
   ```bash
    cd C:/LearningCpp/MakeAndCmake/VersioningExample/build
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
3. **Run the Executable: Navigate to the Release directory and run the test executable**:
    ```bash
    cd C:/LearningCpp/MakeAndCmake/VersioningExample/build/Release
    .\Versioning.exe
    