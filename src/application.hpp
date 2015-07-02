#ifndef TURING_MACHINE_APPLICATION
#define TURING_MACHINE_APPLICATION

#include <memory>
#include <string>

#include <FL/Fl_Window.H>

#include "popup.hpp"
#include "menu.hpp"
#include "states_table.hpp"
#include "state_map.hpp"

class Controller;

class Application : public Fl_Window {
public:
    typedef std::unique_ptr<Fl_Box> BoxPtr;
    typedef std::unique_ptr<Fl_Button> ButtonPtr;
    typedef std::unique_ptr<Popup> PopupPtr;
    typedef std::unique_ptr<StatesTable> TablePtr;
    typedef std::unique_ptr<Menu> MenuPtr;

    Application(Controller* ctrl);

    void refresh(const StateMap& state_map);

    static void add_button(Fl_Widget*, void*);

private:
    Controller* ctrl_;

    MenuPtr menu_;
    TablePtr table_;
    PopupPtr popup_;

    BoxPtr box;
    BoxPtr tape;
    BoxPtr service;

    ButtonPtr add;
    ButtonPtr start;

    BoxPtr state_beg;
    BoxPtr read_sym;
    BoxPtr write_sym;
    BoxPtr dir;
    BoxPtr state_end;
};


#endif
