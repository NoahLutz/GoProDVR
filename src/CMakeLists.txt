include_directories(${GoProDVR_SOURCE_DIR}/include)

file(GLOB_RECURSE SRCS
    *.cpp
    *.glade
)

add_executable(GoProDVR ${SRCS})
target_link_libraries(GoProDVR ${GTKMM3_LIBRARIES} ${GTK3_LIBRARIES} ${LIBVLC_LIRBARIES} ${X11_LIBRARIES} vlc)

add_custom_command(
    TARGET GoProDVR
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/resources/GoProDVR.glade
            ${CMAKE_BINARY_DIR}/GoProDVR.glade)
