#include "application.hpp"
#include <iostream>
#include "statesTable.hpp"
#include <string>

#include <memory>
#include <fstream>

Menu::Menu(Application* app): Fl_Menu_Bar(-1, 0, app->w() + 3, 30), app_(app) {
    add("Program", 0, 0, 0, FL_SUBMENU);
	add("Program/Nowy program", FL_CTRL + 'n', new_machine );
	add("Program/Otworz", FL_CTRL + 'o', open_load_machine, this );
    add("Program/Zapisz", FL_CTRL + 's', open_save_machine, this, FL_MENU_DIVIDER);
	add("Program/Zakoncz", 0, endProgram );

	add("Opcje", 0, 0, 0, FL_SUBMENU);
	add("Opcje/Informacje o programie", FL_CTRL + 'i', show_information );



	save_->filename_label = "Nazwa pliku:";
	save_->show_label = "Pokazuj:";
	save_->all_files_label = "Wszystkie pliki (*)";
	save_->custom_filter_label = "Wlasny filtr";
	save_->add_favorites_label = "Dodaj do ulubionych";
	save_->favorites_label = "Ulubione";
	save_->manage_favorites_label = "Zarzadzaj ulubionymi";
	save_->filesystems_label = "Moj komputer";
	fl_cancel="Anuluj";

    save_ = FileChooserPtr(new Fl_File_Chooser("C://", "*", Fl_File_Chooser::CREATE, "Zapisywanie"));
    save_->preview( 0 );
    save_->ok_label( "Zapisz" );
    save_->previewButton->hide();
    save_->newButton->hide();
    save_->callback(save_machine, app_);




	open_->filename_label = "Nazwa pliku:";
	open_->show_label = "Pokazuj:";
	open_->all_files_label = "Wszystkie pliki (*)";
	open_->custom_filter_label = "Wlasny filtr";
	open_->add_favorites_label = "Dodaj do ulubionych";
	open_->favorites_label = "Ulubione";
	open_->manage_favorites_label = "Zarzadzaj ulubionymi";
	open_->filesystems_label = "Moj komputer";
	fl_cancel="Anuluj";

    open_ = FileChooserPtr(new Fl_File_Chooser("C://", "*.tur", Fl_File_Chooser::SINGLE, "Otwieranie"));
    open_->preview( 0 );
    open_->ok_label( "Otworz" );
    open_->previewButton->hide();
    open_->newButton->hide();
    open_->callback(open_machine, app_);
}



void Menu::open_save_machine(Fl_Widget*, void* menu) {
    static_cast<Menu*>(menu)->save_->show();
}

void Menu::save_machine(Fl_File_Chooser* e, void* app) {
	if( !e->visible() )
		static_cast<Application*>(app)->save_machine(e->value());
}


void Menu::open_load_machine(Fl_Widget*, void* menu)
{
	static_cast<Menu*>(menu)->open_->show();
}
void Menu::open_machine(Fl_File_Chooser* e, void* app)
{
	if( !e->visible() )
		static_cast<Application*>(app)->open_machine(e->value());
}


void Menu::new_machine(Fl_Widget* e, void*)
{
	Fl_Menu_Bar* btn = dynamic_cast<Fl_Menu_Bar*>(e);
    Application* app = dynamic_cast<Application*>(btn->parent());
   Application::clir(app);
}

void Menu::open_existing_machine( Fl_Widget*, void* )
{
}
void Menu::show_information( Fl_Widget*, void* )
{
	fl_message_title("Informacje o programie");
	fl_close="Zamknij";
	fl_message("Aktualna wersja programu:1.0.0 \n\nProgram MaszynaTuringa zostal opracowany przez Michala Muskale "
		"oraz Kamila Kryusa \nna potrzeby projektu szkolnego. By dowiedziec sie wiecej porozmawiaj z autorami programu.");
}
void Menu::endProgram( Fl_Widget* e, void* )
{
	((Fl_Widget*) e)->parent()->hide();
}