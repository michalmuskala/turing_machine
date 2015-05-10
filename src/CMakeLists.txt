add_executable(machine main.cpp machine.cpp)

target_link_libraries(machine ${FLTK_LIBRARIES} ${OpenGL_Libraries})
