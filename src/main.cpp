#include <FL/Fl.H>
#include <iostream>

#include "machine.hpp"
#include "application.hpp"
#include <FL/Fl_Window.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Box.H>
#include "statesTable.hpp"
#include <iostream>

int main()
{
     //Machine machine;
    // machine.parse(std::cin);

    // Machine::callback_type callback = [](const state_type& state, const sym_type sym) {
    //     std::cerr << state << " " << sym << std::endl;
    // };

    // machine.register_callback(callback);

    // std::cerr << machine.run() << std::endl;

    Application application(600, 500);
    return Fl::run();


}