cmake_minimum_required(VERSION 3.10)

project(GoProDVR)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtkmm-3.0)
pkg_check_modules(LIBVLC REQUIRED libvlc)

include_directories(${GTK3_INCLUDE_DIRS} ${LIBVLC_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS} ${LIBVLC_INCLUDE_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src)
