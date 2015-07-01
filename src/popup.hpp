#include "state_map.hpp"
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include "statesTable.hpp"
#include <memory>

class Application;

class Popup: public Fl_Window {
public:
	typedef std::unique_ptr<Fl_Box> BoxPtr;
    Popup(StateMap* state_map, statesTable* table);
	static void send_order_input(Fl_Widget*, void*);
private:
    StateMap* state_map_;
	statesTable* table_;
	
};