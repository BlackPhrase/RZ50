project(RZ-Core)

# Set the output name for this lib
set(PROJECT_TARGET_CORE RZCore)

# Available options
option(RZ_CORE_ENABLE_TESTING_IMPL "Enable building of testing functionality classes" ON)

# Add include files search directories
include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

# Generate a list of project sources
file(GLOB PROJECT_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

set(PROJECT_SOURCES_EXTERNAL
	${CMAKE_SOURCE_DIR}/external/iniparser/src/iniparser.c
	${CMAKE_SOURCE_DIR}/external/iniparser/src/dictionary.c
)

list(APPEND PROJECT_SOURCES ${PROJECT_SOURCES_EXTERNAL})

if(RZ_CORE_ENABLE_TESTING_IMPL)
	file(GLOB PROJECT_SOURCES_TESTING
		${CMAKE_CURRENT_SOURCE_DIR}/testing/*.cpp
	)
	
	list(APPEND PROJECT_SOURCES ${PROJECT_SOURCES_TESTING})
endif()

# Add platform/implementation-specific sources
add_subdirectory(impl)

# Build as shared lib
add_library(${PROJECT_TARGET_CORE} MODULE ${PROJECT_SOURCES})

# Set properties
set_target_properties(${PROJECT_TARGET_CORE} PROPERTIES
	PREFIX ""
)

#target_link_libraries(${PROJECT_TARGET_CORE} iniparser)
#add_dependencies(${PROJECT_TARGET_CORE} iniparser)