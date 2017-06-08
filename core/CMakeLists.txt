project(RZ-Core)

# Set the output name for this lib
set(PROJECT_TARGET_CORE RZCore)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

# Generate a list of project sources
file(GLOB_RECURSE PROJECT_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

# Build as shared lib
add_library(${PROJECT_TARGET_CORE} MODULE ${PROJECT_SOURCES})

# Set properties
set_target_properties(${PROJECT_TARGET_CORE} PROPERTIES
	PREFIX ""
)