add_executable(machine main.cpp machine.cpp application.cpp states_table.cpp state_map.cpp menu.cpp popup.cpp controller.cpp tape.cpp)

target_link_libraries(machine ${FLTK_LIBRARIES} ${OpenGL_Libraries})
