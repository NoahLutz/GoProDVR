cmake_minimum_required(VERSION 3.10)

project(gtkmmSpike)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtkmm-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

file(GLOB SRCS
    *.cpp
    *.h
)

add_executable(gtkmmSpike ${SRCS})
target_link_libraries(gtkmmSpike ${GTK3_LIBRARIES})
