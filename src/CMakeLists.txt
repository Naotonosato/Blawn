 file(GLOB LLVM /usr/lib64/llvm6.0/libLLVM-6.0.so)

add_subdirectory(blawn)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} lib-blawn ${LLVM})
