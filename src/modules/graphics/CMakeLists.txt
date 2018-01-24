project(RZ-Graphics)

# Set the output name for this lib
set(PROJECT_TARGET_GRAPHICS RZGraphics)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

# Generate a list of project sources
file(GLOB PROJECT_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_subdirectory(impl)

# Build as shared lib
add_library(${PROJECT_TARGET_GRAPHICS} MODULE ${PROJECT_SOURCES})

# Set properties
set_target_properties(${PROJECT_TARGET_GRAPHICS} PROPERTIES
	PREFIX ""
)

if(WIN32)
	target_link_libraries(${PROJECT_TARGET_GRAPHICS} -lopengl32)
else()
# TODO
endif()