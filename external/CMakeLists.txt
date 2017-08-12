add_custom_target(
   iniparser
   COMMAND make
   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/iniparser
)

#add_executable(myexecutable myexcutable.c)
#target_link_libraries(myexecutable full_path_to_generated_library)
#add_dependencies(myexecutable extern_lib)