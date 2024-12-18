# --------------------------------------------------------------------------------------------------
# Top level Project configuration
# --------------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.30)

project(sdl2-platformer-demo LANGUAGES CXX)

# --------------------------------------------------------------------------------------------------
# Setup cmake module directories
#
# @see https://cmake.org/cmake/help/latest/variable/CMAKE_MODULE_PATH.html
# --------------------------------------------------------------------------------------------------

set(DEPENDENCIES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dependencies")

list(
    APPEND
    CMAKE_MODULE_PATH

    "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
    "${DEPENDENCIES_DIR}"
)

# --------------------------------------------------------------------------------------------------
# Compiler setup and utilities
# --------------------------------------------------------------------------------------------------

include("cpp-standard")
include("compiler-options")
include("utilities")

# --------------------------------------------------------------------------------------------------
# Project's source files
# --------------------------------------------------------------------------------------------------

# Header files
include_directories("${PROJECT_SOURCE_DIR}/include")

# Add all c source files under the src directory
file(GLOB SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

# --------------------------------------------------------------------------------------------------
# Dependencies
# --------------------------------------------------------------------------------------------------

include("dependencies.cmake")