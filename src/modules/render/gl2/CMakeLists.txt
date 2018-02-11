project(RZ-RenderGL2)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

# Generate a list of project sources
file(GLOB PROJECT_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

# Build as shared lib
add_library(${PROJECT_NAME} MODULE ${PROJECT_SOURCES})

# Set properties
set_target_properties(${PROJECT_NAME} PROPERTIES
	OUTPUT_NAME "RZRender-GL2"
	PREFIX ""
)

if(WIN32)
	target_link_libraries(${PROJECT_NAME} -lopengl32)
else()
	# TODO
endif()