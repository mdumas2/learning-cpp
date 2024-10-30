# My Dynamic Library Example

This repository demonstrates how to create and use a CMake file with git submodule.

This example will use the [glfw library](https://github.com/glfw/glfw)

For using submodules will would use the following command

    git submodule add https://github.com/glfw/glfw.git external/glfw

## Directory Structure

```
C:.
└── LearningCpp
    └── MakeAndCmake
        └── GitSubModuleExample
            ├── CMakeLists.txt          # CMake configuration for the test project
            ├── main.cpp                # Main program file
            ├── build                   # Build directory for compiled files
            └── external
                └── glfw          
```

## Build the Test Project
1. **Navigate to the Test Project Build Directory**:
   ```bash
    cd C:/LearningCpp/MakeAndCmake/GitSubModuleExample/build
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
    cd C:/LearningCpp/MakeAndCmake/DynamicLibrariesExample/build/Release
    .\testdynamiclib.exe
    