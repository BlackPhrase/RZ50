project(RZ-Physics)

# Detect the impl type
if(NOT RZ_PHYSICS_IMPL_TYPE)
    set(RZ_PHYSICS_IMPL_TYPE Null CACHE STRING
        "Choose the type of implementation, options are: Null Simple."
        FORCE
	)
    set_property(CACHE RZ_PHYSICS_IMPL_TYPE PROPERTY STRINGS
		Null
		Simple
	)
endif()

# Add include directories
include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

# Generate a list of project sources
file(GLOB PROJECT_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

#string(TOLOWER ${RZ_PHYSICS_IMPL_TYPE} RZ_PHYSICS_IMPL_TYPE)
add_subdirectory(${RZ_PHYSICS_IMPL_TYPE})

# Build as shared lib
add_library(${PROJECT_NAME} MODULE ${PROJECT_SOURCES})

# Set properties
set_target_properties(${PROJECT_NAME} PROPERTIES
	PREFIX ""
	OUTPUT_NAME "RZPhysics${RZ_PHYSICS_IMPL_TYPE}"
)