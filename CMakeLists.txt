cmake_minimum_required(VERSION 3.20.0)
project(awesome-bloom-filters VERSION 0.0.1 LANGUAGES C CXX)

INCLUDE(CMakeForceCompiler)
CMAKE_FORCE_C_COMPILER(gcc GNU)
CMAKE_FORCE_CXX_COMPILER(g++ GNU)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
    message("Setting default build type to Release")
endif()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(./src)

add_subdirectory(./test)