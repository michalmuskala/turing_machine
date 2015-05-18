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

int main()
{
    Machine machine;
    machine.parse(std::cin);

    Machine::callback_type callback = [](const state_type& state, const sym_type sym) {
        std::cerr << state << " " << sym << std::endl;
    };

    machine.register_callback(callback);

    std::cerr << machine.run() << std::endl;

    return Fl::run();
}
