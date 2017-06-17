project(RZ-Sound)

# Set the output name for this lib
set(PROJECT_TARGET_SOUND RZSound)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

# Generate a list of project sources
file(GLOB PROJECT_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

# Build as shared lib
add_library(${PROJECT_TARGET_SOUND} MODULE ${PROJECT_SOURCES})

# Set properties
set_target_properties(${PROJECT_TARGET_SOUND} PROPERTIES
	PREFIX ""
)