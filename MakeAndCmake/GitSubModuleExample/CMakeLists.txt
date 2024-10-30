cmake_minimum_required(VERSION 3.27.4)

project(testsub)

add_executable(${PROJECT_NAME} main.cpp)

find_package(Git QUIET)
message(STATUS "Submodule update")
if(NOT GIT_FOUND)
	message(STATUS "Git not found!")
elseif(NOT EXISTS "${PROJECT_SOURCE_DIR}/../../.git")
	message(STATUS "No .git directory found! Are you in a Git repository?")
else()
	message(STATUS "Git found and .git directory exists.")
	option(GIT_SUBMODULE "Check submodules during build" ON)
	if(GIT_SUBMODULE)
		message(STATUS "CMAKE_CURRENT_SOURCE_DIR is set to: ${CMAKE_CURRENT_SOURCE_DIR}")
		execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
						WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
						RESULT_VARIABLE GIT_SUBMOD_RESULT)
		if(NOT GIT_SUBMOD_RESULT EQUAL "0")
			message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
		else()
			message(STATUS "Submodule update succeeded.")
		endif()
	endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
	message(FATAL_ERROR "The glfw submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME}  
	PUBLIC external/glfw/include
)

target_link_directories(${PROJECT_NAME} 
	PRIVATE external/glfw/src
)

target_link_libraries(${PROJECT_NAME}  
	glfw
)
