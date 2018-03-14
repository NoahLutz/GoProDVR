cmake_minimum_required(VERSION 3.10)

project(libvlcppDemo)

find_package(PkgConfig REQUIRED)
PKG_CHECK_MODULES(LIBVLCPP REQUIRED libvlcpp)

if(LIBVLCPP_FOUND)
    message(STATUS "Found libvlcpp")
    message(STATUS ${LIBVLCPP_INCLUDE_DIRS})
endif(LIBVLCPP_FOUND)

include_directories(${LIBVLCPP_INCLUDE_DIRS})
link_directories(${LIBVLCPP_LIBRARY_DIRS})

add_executable(libvlcppDemo main.cpp)

target_link_libraries(libvlcppDemo ${LIBVLCPP_LIBRARIES})
