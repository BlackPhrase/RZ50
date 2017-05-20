project(RZ-Core)

# Set the output name for this lib
set(PROJECT_OUTPUT_NAME RZCore)

# Generate a list of project sources
file(GLOB_RECURSE PROJECT_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

# Build as shared lib
add_library(${PROJECT_OUTPUT_NAME} SHARED ${PROJECT_SOURCES})