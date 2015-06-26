#include "application.hpp"
#include <iostream>
#include "statesTable.hpp"
#include <string>


Fl_Menu_Item menuitems[] =
{
	{ "Program", 0, 0, 0, FL_SUBMENU },
	{ "&Nowy program", FL_CTRL + 'p', (Fl_Callback *)Application::new_machine },
	{ "&Otwórz program", FL_CTRL + 'o', (Fl_Callback *)Application::open_machine },
	{ "Zapisz program", FL_CTRL + 's', (Fl_Callback *)Application::save_machine, 0, FL_MENU_DIVIDER },
	{ "Koniec", 0, (Fl_Callback *)Application::exit },
	{ 0 },
	{ "Opcje", 0, 0, 0, FL_SUBMENU },
	{ "&Informacje o programie", FL_CTRL + 'i', (Fl_Callback *)Application::show_information },
	{ 0 },
};



Application::Application(int w, int h): Fl_Window(w, h, "Maszyna Turinga"),
                                        w_(w), h_(h) {
  menu_Bar = MenuBarPtr(new Fl_Menu_Bar( 0, 0, w_, 30));
	menu_Bar->copy( menuitems );
	

	tape = BoxPtr(new Fl_Box(0, 60, w_, 30, "TAPE"));
	tape->box(FL_UP_BOX);

	service = BoxPtr(new Fl_Box(-1,90,w_,50,"Start, Add, etc."));
	service->box(FL_UP_BOX);

	add = ButtonPtr(new Fl_Button(5, 100, 50, 30, "Dodaj"));
	add->callback(add_button);

	start = ButtonPtr(new Fl_Button(75, 100, 50, 30, "Start"));
	start->callback(open_machine);
	
	box = BoxPtr(new Fl_Box(-1,29,w_,471,"StatesTable"));
	state_beg = BoxPtr(new Fl_Box(27,170, 120,30,"Stan poczatkowy"));
	state_beg->box(FL_BORDER_BOX);
	read_sym = BoxPtr(new Fl_Box(146,170, 140,30,"Przeczytany symbol"));
	read_sym->box(FL_BORDER_BOX);
	write_sym = BoxPtr(new Fl_Box(285,170, 120,30,"Wpisany symbol"));
	write_sym->box(FL_BORDER_BOX);
	dir = BoxPtr(new Fl_Box(403,170, 70,30,"Kierunek"));
	dir->box(FL_BORDER_BOX);
	state_end = BoxPtr(new Fl_Box(472,170, 100,30,"Stan koncowy"));
	state_end->box(FL_BORDER_BOX);

	
	end();
    show();
}
Application::~Application( void)
{
}


void Application::new_machine( Fl_Widget*, void* )
{
}
void Application::open_machine( Fl_Widget*, void* )
{
	Fl_File_Chooser *fc;
	fc = new Fl_File_Chooser( "c:\\", "*.tur",
	Fl_File_Chooser::SINGLE, "Otwieranie" );
	fc->preview( 0 );
	fc->ok_label( "Otwórz" );
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
	fl_message("Tutaj beda jakies informacje o programie?");
	
}
void Application::exit( Fl_Widget* e )
{
	((Fl_Widget*) e)->parent()->hide();
}

void Application::add_button(Fl_Widget*, void*)
{

	Fl_Window window(250, 250, "Dodaj rozkaz");
	Fl_Input *input;
	input = new Fl_Input(60, 20, 150, 25, "Symbol: ");
	input -> value("");
	Fl_Box *symbolText = new Fl_Box(10,60,230,50,"Symbol, ktory bedzie wpisany\n na tasme.");


	input = new Fl_Input(70, 120, 150, 25, "Kierunek: ");
	input -> value("");
	Fl_Box *directionText = new Fl_Box(10,150,230,50,"Kierunek nastepnego ruchu glowicy.");

	Fl_Button *addOrder;
	addOrder = new Fl_Button(180, 200, 50, 30, "Dodaj");
	addOrder->callback(open_machine);

	
	window.end();
	window.show();
	Fl::run();

}
