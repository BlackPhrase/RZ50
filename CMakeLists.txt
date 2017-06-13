cmake_minimum_required(VERSION 3.6) # 3.8
project(RZ-50)

# Setup version
set(RZ_VERSION_MAJOR 0)
set(RZ_VERSION_MINOR 1)
set(RZ_VERSION_PATCH 3)

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

# Set C++ standard
set(CMAKE_CXX_STANDARD 14) # 17

# Set compiled binaries output directory
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# Set flags for C++ code compilation
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} -Os")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -g -O3")

# Add include directories
include_directories(
	${CMAKE_SOURCE_DIR}/common
	${CMAKE_SOURCE_DIR}/../shiftutil/include
)

# Add subdirectories
add_subdirectory(tests)
add_subdirectory(launcher)
add_subdirectory(core)
add_subdirectory(subsystems)
#add_subdirectory(game)
add_subdirectory(plugins)