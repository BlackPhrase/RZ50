#cmake_minimum_required(VERSION ??)
project(RZ-50)

# Setup version
set(RZ_VERSION_MAJOR 0)
set(RZ_VERSION_MINOR 1)
set(RZ_VERSION_PATCH 2)

# Detect the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING
        "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel."
        FORCE
	)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
		None Debug Release RelWithDebInfo MinSizeRel
	)
endif()

# Set CMake modules path
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# Set compiled binaries output directory
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# Add include directories
include_directories(
	${CMAKE_SOURCE_DIR}/common
)

# Add subdirectories
add_subdirectory(tests)
add_subdirectory(launcher)
add_subdirectory(core)
add_subdirectory(subsystems)
add_subdirectory(game)