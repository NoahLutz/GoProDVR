cmake_minimum_required(VERSION 3.10)
project (libvlcDemo)

find_package(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK REQUIRED gtk+-3.0)

if(GTK_FOUND)
    message(STATUS "FOUND GTK3")
    message(STATUS ${GTK_INCLUDE_DIRS})
    message(STATUS ${GTK_LIBRARY_DIRS})
endif(GTK_FOUND)

include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})

add_definitions(${GTK_CFLAGS_OTHER})

add_executable (libvlcDemo libvlcDemo.cpp)
target_link_libraries(libvlcDemo vlc ${GTK_LIBRARIES})
