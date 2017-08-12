project(RZ-Launcher)

# Target name
set(PROJECT_TARGET_LAUNCHER launcher)

#
file(GLOB PROJECT_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

#
include_directories(
	${CMAKE_SOURCE_DIR}/core
	${CMAKE_SOURCE_DIR}/subsystems
)

# Build as executable app
add_executable(${PROJECT_TARGET_LAUNCHER}
	${PROJECT_SOURCES}
)

set_target_properties(${PROJECT_TARGET_LAUNCHER} PROPERTIES
	OUTPUT_NAME "Game"
)

target_link_libraries(${PROJECT_TARGET_LAUNCHER}
	#${PROJECT_TARGET_CORE}
)