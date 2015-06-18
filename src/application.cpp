#include "application.hpp"

Application::Application(int w, int h): Fl_Window(w, h, "Maszyna Turinga"),
                                        w_(w), h_(h) {
    end();
    show();
}
