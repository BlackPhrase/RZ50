project(RZ-Core)

# Set the output name for this lib
set(PROJECT_TARGET_CORE RZCore)

# Add include files search directories
include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

# Generate a list of project sources
file(GLOB PROJECT_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

# Add platform/implementation-specific sources
add_subdirectory(impl)

# Build as shared lib
add_library(${PROJECT_TARGET_CORE} MODULE ${PROJECT_SOURCES})

# Set properties
set_target_properties(${PROJECT_TARGET_CORE} PROPERTIES
	PREFIX ""
)