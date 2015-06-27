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
  menu_Bar = MenuBarPtr(new Fl_Menu_Bar( -1, 0, w_+3, 30));
	menu_Bar->copy( menuitems );
	

	tape = BoxPtr(new Fl_Box(-1, 60+1, w_+3, 30, "TAPE"));
	tape->box(FL_UP_BOX);

	service = BoxPtr(new Fl_Box(-1,90,w_+3,50,"Start, Add, etc."));
	service->box(FL_UP_BOX);

	add = ButtonPtr(new Fl_Button(5, 100, 50, 30, "Dodaj"));
	add->callback(add_button);

	start = ButtonPtr(new Fl_Button(75, 100, 50, 30, "Start"));
	start->callback(open_machine);
	
	box = BoxPtr(new Fl_Box(-1,29,w_,471,"StatesTable"));
	state_beg = BoxPtr(new Fl_Box(12,170, 125,35,"Stan poczatkowy"));
	state_beg->box(FL_BORDER_BOX);

	read_sym = BoxPtr(new Fl_Box(136,170, 145,35,"Przeczytany symbol"));
	read_sym->box(FL_BORDER_BOX);
	write_sym = BoxPtr(new Fl_Box(280,170, 125,35,"Wpisany symbol"));
	write_sym->box(FL_BORDER_BOX);
	dir = BoxPtr(new Fl_Box(404,170, 75,35,"Kierunek"));
	dir->box(FL_BORDER_BOX);
	state_end = BoxPtr(new Fl_Box(478,170, 105,35,"Stan koncowy"));
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
	Fl_Window window(300, 400, "Dodaj rozkaz");
	
	//inputBegState = new Fl_Input(110, 30, 180, 17, "Stan poczatkowy: ");
	BoxPtr begText, rSymText, wSymText, dirText, endText;
	
	inputy::inputBegState = InputPtr(new Fl_Input(110, 30, 180, 17, "Stan poczatkowy: "));
	inputy::inputBegState -> value("");
	inputy::inputBegState->labelsize(11);
	inputy::inputBegState->textsize(11);

	begText = BoxPtr(new Fl_Box(10,50,280,50,"Stan, w jakim maszyna sie znajduje przed \nrozpoczeciem pracy (np.: 'STAN1')."));
	begText->labelsize(11);
	

	/*inputRSym = InputPtr(new Fl_Input(110, 100, 180, 17, "Czytany symbol:   "));
	inputRSym -> value("");
	inputRSym->labelsize(11);
	inputRSym->textsize(11);
	inputRSym->maximum_size(1);

	rSymText = BoxPtr(new Fl_Box(10,115,280,50,"Symbol, ktory bedzie przeczytany z tasmy (np.: '#')."));
	rSymText->labelsize(11);

	inputWSym = InputPtr(new Fl_Input(110, 165, 180, 17, "Zapisany symbol:  "));
	inputWSym -> value("");
	inputWSym->labelsize(11);
	inputWSym->textsize(11);
	inputWSym->maximum_size(1);

	wSymText = BoxPtr(new Fl_Box(10,175,280,50,"Symbol, ktory bedzie zapisany do tasmy (np.: '1')."));
	wSymText->labelsize(11);

	inputDir = InputPtr(new Fl_Input(110, 230, 180, 17, "Kierunek:               "));
	inputDir -> value("");
	inputDir->labelsize(11);
	inputDir->textsize(11);
	inputDir->maximum_size(1);

	dirText = BoxPtr(new Fl_Box(10,240,280,50,"Kierunek nastepnego ruchu glowicy (L lub P)."));
	dirText->labelsize(11);

	inputEndState = InputPtr(new Fl_Input(110, 295, 180, 17, "Stan koncowy:      "));
	inputEndState -> value("");
	inputEndState->labelsize(11);
	inputEndState->textsize(11);

	endText = BoxPtr(new Fl_Box(10,305,280,50,"Stan maszyny, w jakim sie znajdzie \npo wykonaniu rozkazu (np.: 'STAN2')."));
	endText->labelsize(11);*/


	Fl_Button *addOrder;
	addOrder = new Fl_Button(230, 350, 50, 30, "Dodaj");
	addOrder->callback(okej);

	
	window.end();
	window.show();
	Fl::run();

}
void Application::okej(Fl_Widget*, void* param)
{
	//std::cout<<Application::inputBegState->value(); do tego momentu jeszcze nie doszedlem
}