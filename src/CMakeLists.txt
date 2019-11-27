add_subdirectory(blawn)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} lib-blawn ${LLVM})

execute_process(COMMAND "mkdir" -p ${EXECUTABLE_OUTPUT_PATH}/data)
execute_process(COMMAND "mkdir" -p ${EXECUTABLE_OUTPUT_PATH}/tmp)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND "cp" ${PROJECT_BINARY_DIR}/src/blawn/CMakeFiles/lib-blawn.dir/builtins/builtins.c.o ${EXECUTABLE_OUTPUT_PATH}/data/builtins.o)
