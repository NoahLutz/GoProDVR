include_directories(${GoProDVR_SOURCE_DIR}/include)

file(GLOB_RECURSE SRCS
    ./*.cpp
    *.hpp
)

MESSAGE(STATUS "SRCS: " ${SRCS})

add_executable(GoProDVR ${SRCS})
target_link_libraries(GoProDVR ${GTK3_LIBRARIES} ${LIBVLC_LIRBARIES})
