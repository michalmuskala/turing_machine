#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Button.H>
#include <sstream>
#include <cmath>
#include <iostream>

#include "machine.hpp"

Fl_Value_Input* a, *b, *c;
Fl_Multiline_Output* out;

void oblicz_cb(Fl_Widget*, void*) {
    double av = a->value(),
        bv = b->value(),
        cv = c->value();

    double delta = bv * bv - 4 * av * cv;
    std::ostringstream str;

    if (av == 0) {
        str << "To nie jest funkcja kwadratowa.";
    } else if (delta < 0) {
        str << "Brak rozwiazan rzeczywistych.\ndelta = " << delta;
    } else if (delta == 0) {
        str << "Jedno rozwiazanie:\nx1 = " << (double) -bv / 2 * av;
    } else {
        str << "Dwa rozwiazania:" <<
            "\nx1 = " << ((double) -bv + sqrt(delta)) / 2 * av <<
            "\nx2 = " << ((double) -bv - sqrt(delta)) / 2 * av;
    }

    out->value(str.str().c_str());
}

int main()
{
    using namespace machine;
    // Fl_Window w(600, 400, "Solver");

    // Fl_Box title(10, 10, 580, 80, "ax^2 + bx + c = 0");
    // title.box(FL_DOWN_BOX);
    // title.labelsize(36);
    // title.labelfont(FL_BOLD + FL_ITALIC);

    // a = new Fl_Value_Input(100, 120, 100, 20, "a = ");
    // a->value(1);

    // b = new Fl_Value_Input (250, 120, 100, 20, "b = ");
    // b->value(0);

    // c = new Fl_Value_Input (400, 120, 100, 20, "c = ");
    // c->value(0);

    // out = new Fl_Multiline_Output(100, 170, 250, 200, "Wynik:");

    // Fl_Button oblicz(400, 240, 100, 30, "Oblicz");
    // oblicz.callback(oblicz_cb);

    // w.end();
    // w.show();

    Machine machine;
    machine.parse(std::cin);

    Machine::callback_type callback = [](const state_type& state, const sym_type sym) {
        std::cerr << state << " " << sym << std::endl;
    };

    machine.register_callback(callback);

    std::cerr << machine.run() << std::endl;

    return Fl::run();
}
