add_executable(machine main.cpp machine.cpp application.cpp statesTable.cpp state_map.cpp menu.cpp popup.cpp)

target_link_libraries(machine ${FLTK_LIBRARIES} ${OpenGL_Libraries})
