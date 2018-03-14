cmake_minimum_required(VERSION 2.6)
project(Library)

include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
add_subdirectory(MathFunctions)


add_executable(Library main.cpp)
target_link_libraries(Library MathFunctions)

