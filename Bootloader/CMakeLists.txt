cmake_minimum_required(VERSION 3.22)

project(compiler VERSION 0.1.0 LANGUAGES C CXX)

## Set C and C++ standards
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_FLAGS -m32)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS -m32)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build." FORCE)

enable_testing()

add_executable(${PROJECT_NAME} main.cpp)