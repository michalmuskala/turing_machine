#include <FL/Fl.H>
#include <iostream>
#include "machine.hpp"
#include "application.hpp"
#include <FL/Fl_Window.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Box.H>
#include "statesTable.hpp"

int main()
{
     //Machine machine;
    // machine.parse(std::cin);

    // Machine::callback_type callback = [](const state_type& state, const sym_type sym) {
    //     std::cerr << state << " " << sym << std::endl;
    // };

    // machine.register_callback(callback);

    // std::cerr << machine.run() << std::endl;

	/*StateMap state_map;
	
	for (auto i = state_map.begin(); i != state_map.end(); ++i)
	{
		for (auto j = i->second.begin(); j != i->second.end(); ++j)
		{
			std::cout << i->first << " "
				<< j->first << " "
			<< j->second.sym << " "
			<< j->second.move << " "
			<< j->second.state << std::endl;
		}
	}*/
    Application application(600, 500);
    return Fl::run();


}