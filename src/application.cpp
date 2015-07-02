#include "application.hpp"
#include "controller.hpp"
#include "states_table.hpp"

#include <iostream>

Application::Application(Controller* ctrl):
    Fl_Window(600, 500, "Maszyna Turinga"), ctrl_(ctrl) {

    menu_  = MenuPtr(new Menu(ctrl_));
    table_ = TablePtr(new StatesTable(ctrl_));

    tape = BoxPtr(new Fl_Box(-1, 60+1, w()+3, 30, "TAPE"));
    tape->box(FL_UP_BOX);

    service = BoxPtr(new Fl_Box(-1,90,w()+3,50,"Start, Add, etc."));
    service->box(FL_UP_BOX);

    add = ButtonPtr(new Fl_Button(5, 100, 50, 30, "Dodaj"));
    add->callback(add_button, this);

    start = ButtonPtr(new Fl_Button(75, 100, 50, 30, "Start"));
    //start->callback();

    popup_ = PopupPtr(new Popup(ctrl_));

    end();
    show();
}

void Application::add_button(Fl_Widget* e, void* app) {
    static_cast<Application*>(app)->popup_->show();
}

void Application::refresh(const StateMap& state_map) {
    table_->refresh(state_map);
    table_->redraw();
}
