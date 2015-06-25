#include "application.hpp"
#include <iostream>
#include "statesTable.hpp"
#include <string>

Fl_Menu_Item menuitems[] =
{
	{ "Program", 0, 0, 0, FL_SUBMENU },
	{ "&Nowy program", FL_CTRL + 'p', (Fl_Callback *)Application::new_machine },
	{ "&Otw�rz program", FL_CTRL + 'o', (Fl_Callback *)Application::open_machine },
	{ "Zapisz program", FL_CTRL + 's', (Fl_Callback *)Application::save_machine, 0, FL_MENU_DIVIDER },
	{ "Koniec", 0, (Fl_Callback *)Application::exit },
	{ 0 },
	{ "Opcje", 0, 0, 0, FL_SUBMENU },
	{ "&Informacje o programie", FL_CTRL + 'i', (Fl_Callback *)Application::show_information },
	{ 0 },
};



Application::Application(int w, int h): Fl_Window(w, h, "Maszyna Turinga"),
                                        w_(w), h_(h) {
	menu_Bar = new Fl_Menu_Bar( 0, 0, w_, 30);
	menu_Bar->copy( menuitems );

	end();
    show();
}
Application::~Application( void)
{
	delete menu_Bar;
}


void Application::new_machine( Fl_Widget*, void* )
{
}
void Application::open_machine( Fl_Widget*, void* )
{
	Fl_File_Chooser *fc;
	fc = new Fl_File_Chooser( "c:\\", "*.turm",
	Fl_File_Chooser::SINGLE, "Otwieranie" );
	fc->preview( 0 );
	fc->ok_label( "Otw�rz" );
	fc->previewButton->hide();
	fc->newButton->hide();
	fc->callback( open_tur );
	fc->show();
}
void Application::open_tur( Fl_File_Chooser* o, void *v )
{
	std::string pathname;
	pathname=o->value();
if( !o->visible() )
	std::cout<<pathname;
}

void Application::save_machine( Fl_Widget*, void* )
{

}
void Application::show_information( Fl_Widget*, void* )
{
}
void Application::exit( Fl_Widget* e )
{
	((Fl_Widget*) e)->parent()->hide();
}
