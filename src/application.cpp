#include "application.hpp"
#include "controller.hpp"
#include "states_table.hpp"

#include <iostream>

Application::Application(Controller* ctrl):
    Fl_Window(600, 800, "Maszyna Turinga"), ctrl_(ctrl) {

    menu_  = MenuPtr(new Menu(ctrl_));
    table_ = TablePtr(new StatesTable(ctrl_));
    tape_  = TapePtr(new Tape(ctrl_));

    state_ = BoxPtr(new Fl_Box(170,90,430,50,"STATE"));
    state_->box(FL_UP_BOX);

    add = ButtonPtr(new Fl_Button(5, 100, 50, 30, "Dodaj"));
    add->callback(add_button, this);

    start = ButtonPtr(new Fl_Button(75, 100, 50, 30, "Start"));
    start->callback(start_button, ctrl_);

    popup_ = PopupPtr(new Popup(ctrl_));

    end();
    show();
}

void Application::add_button(Fl_Widget*, void* app) {
    static_cast<Application*>(app)->popup_->show();
}

void Application::refresh_state(const StateMap& state_map) {
    table_->refresh(state_map);
    table_->redraw();
}

void Application::refresh_tape(const std::string& state, const std::string& strip, size_t pos) {
    state_->label(state.c_str());
    tape_->refresh(strip, pos);
    redraw();
}

void Application::start_button(Fl_Widget*, void* ctrl) {
    static_cast<Controller*>(ctrl)->start();
}
