project(RZ-Network)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

# Generate a list of project sources
file(GLOB PROJECT_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

# Build as a shared lib
add_library(${PROJECT_NAME} MODULE ${PROJECT_SOURCES})

# Set properties
set_target_properties(${PROJECT_NAME} PROPERTIES
	OUTPUT_NAME "RZNetwork"
)