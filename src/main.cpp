#include <FL/Fl.H>

#include "controller.hpp"

int main()
{
    Controller controller;

    fl_close = "Zamknij";
    fl_cancel = "Anuluj";

    return Fl::run();
}
