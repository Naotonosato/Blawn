cmake_minimum_required(VERSION 3.13)

project(blawn CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# Disable in-source build
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)

# Set default build type
if(NOT CMAKE_BUILD_TYPE)
		  set(CMAKE_BUILD_TYPE Release)
	endif()
	message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Set compiler flags
set(CMAKE_CXX_EXTENSIONS  OFF)
set(CMAKE_CXX_STANDARD    17)
set(CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS}         -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG}   -g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -march=native -DNDEBUG")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS}  -Wl,-O1,--sort-common,--as-needed,-z,relro,-lstdc++fs")

if(CMAKE_GENERATOR STREQUAL "Ninja")
		if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
				set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=always")
		elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
				set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcolor-diagnostics")
		 endif()
endif()

# Sanitizers
if(ENABLE_SANITIZERS)
		if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
				message(STATUS "Enabling GCC's address sanitizer")
				set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
		elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
				message(STATUS "Enabling Clang's address sanitizer")
				set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
		endif()
endif()

find_package(LLVM)
add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_ICLUDE_DIRS})

# LLVM LINK OPTIONの解決
set(LLVM "/usr/bin/llvm-config-6.0-64 --cxxflags --system-libs --ldflags --libs core")
execute_process(COMMAND "echo AAAA"
		OUTPUT_VARIABLE LLVM_LINK_OPTION)
message(STATUS "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa ${LLVM}")
message(STATUS "${LLVM_LINK_OPTION}")

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(/usr/lib64/llvm6.0/include)

add_subdirectory(src)
