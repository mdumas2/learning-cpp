cmake_minimum_required(VERSION 3.27.4)

project(Versioning VERSION 1.0.0)

configure_file(VersioningConfig.h.in VersioningConfig.h)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})