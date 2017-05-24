project(RZ-Launcher)

#
set(PROJECT_OUTPUT_NAME Game)

#
file(GLOB PROJECT_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

# Build as executable app
add_executable(${PROJECT_OUTPUT_NAME}
	${PROJECT_SOURCES}
)