#cmake_minimum_required(VERSION ??)
project(RZ-50)

# Setup version
set(RZ_VERSION_MAJOR 0)
set(RZ_VERSION_MINOR 1)
set(RZ_VERSION_PATCH 0)

# Set CMake modules path
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)

# Add our subdirectories
add_subdirectory(core)
add_subdirectory(fs)
add_subdirectory(game)
add_subdirectory(graphics)
add_subdirectory(input)
add_subdirectory(launcher)
add_subdirectory(network)
add_subdirectory(physics)
add_subdirectory(sound)
add_subdirectory(system)