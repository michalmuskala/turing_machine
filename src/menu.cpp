#include "application.hpp"
#include <iostream>
#include "statesTable.hpp"
#include <string>

#include <memory>
#include <fstream>

Menu::Menu(Application* app): Fl_Menu_Bar(-1, 0, app->w() + 3, 30), app_(app) {
    add("Program", 0, 0, 0, FL_SUBMENU);
    add("Zapisz", FL_CTRL + 's', open_save_machine, this, FL_MENU_DIVIDER);

    save_ = FileChooserPtr(new Fl_File_Chooser(".", "*", Fl_File_Chooser::CREATE, "Zapisywanie"));
    save_->preview( 0 );
    save_->ok_label( "Zapisz" );
    save_->previewButton->hide();
    save_->newButton->hide();
    save_->callback(save_machine, app_);
}

void Menu::open_save_machine(Fl_Widget*, void* menu) {
    static_cast<Menu*>(menu)->save_->show();
}

void Menu::save_machine(Fl_File_Chooser* e, void* app) {
    static_cast<Application*>(app)->save_machine(e->value());
}

