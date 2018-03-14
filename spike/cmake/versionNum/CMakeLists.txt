cmake_minimum_required (VERSION 2.6)
project (SquareRoot)

set (SquareRoot_VERSION_MAJOR 1)
set (SquareRoot_VERSION_MINOR 0)

configure_file (
    "${PROJECT_SOURCE_DIR}/SquareRootConfig.h.in"
    "${PROJECT_BINARY_DIR}/SquareRootConfig.h"
    )

include_directories("${PROJECT_BINARY_DIR}")

add_executable(sqrt sqrt.cpp)
