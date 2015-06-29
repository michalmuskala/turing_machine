#include "application.hpp"
#include <iostream>
#include "statesTable.hpp"
#include <string>

#include <fstream>


Fl_Menu_Item menuitems[] =
{
	{ "Program", 0, 0, 0, FL_SUBMENU },
	{ "&Nowy program", FL_CTRL + 'n', (Fl_Callback *)Application::new_machine },
	{ "&Otwórz program", FL_CTRL + 'o', (Fl_Callback *)Application::open_machine },
	{ "Zapisz program", FL_CTRL + 's', (Fl_Callback *)Application::save_machine, 0, FL_MENU_DIVIDER },
	{ "Zakoncz", 0, (Fl_Callback *)Application::exit },
	{ 0 },
	{ "Opcje", 0, 0, 0, FL_SUBMENU },
	{ "&Informacje o programie", FL_CTRL + 'i', (Fl_Callback *)Application::show_information },
	{ 0 },
};

void rusz_cb( Fl_Widget* o, void* v )
{
double wartosc = ((Fl_Slider* ) o)->value();
/* ... */
}

Application::Application(int w, int h): Fl_Window(w, h, "Maszyna Turinga"),
                                        w_(w), h_(h), state_map() {
	menu_Bar = MenuBarPtr(new Fl_Menu_Bar( -1, 0, w_+3, 30));
	menu_Bar->copy( menuitems );
	std::cout<<menu_Bar->size();
	tape = BoxPtr(new Fl_Box(-1, 60+1, w_+3, 30, "TAPE"));
	tape->box(FL_UP_BOX);

	service = BoxPtr(new Fl_Box(-1,90,w_+3,50,"Start, Add, etc."));
	service->box(FL_UP_BOX);

	add = ButtonPtr(new Fl_Button(5, 100, 50, 30, "Dodaj"));
	add->callback(add_button);

	start = ButtonPtr(new Fl_Button(75, 100, 50, 30, "Start"));
	start->callback(open_machine);
	statesTable table;
	/*Fl_Slider *suwak;
	suwak = new Fl_Slider( w_-15, 170, 20, h_, "");
	suwak->range( -5, 5 ); //zakres wartoœci
	suwak->step( 0.1 ); //krok
	suwak->value( 0 );
	suwak->callback( rusz_cb ); */

	table.height=170;
	table.addRow("STAN0", "#", "1", "L", "STAN1");//przy 9 wlaczyc suwak
	//table.addRow("STAN1", "#", "0", "L", "STAN2");
	//table.addRow("STAN1", "#", "0", "L", "STAN2");
	//table.addRow("STAN1", "#", "0", "L", "STAN2");
	//table.addRow("STAN1", "#", "0", "L", "STAN2");
	//table.addRow("STAN1", "#", "0", "L", "STAN2");
	//table.addRow("STAN1", "#", "0", "L", "STAN2");
	//table.addRow("STAN1", "#", "0", "L", "STAN2");
	//table.addRow("STAN1", "#", "0", "L", "STAN2");
	//table.addRow("STAN1", "#", "0", "L", "STAN2");
	//table.addRow("STAN1", "#", "0", "L", "STAN2");
	//table.addRow("STAN1", "#", "0", "L", "STAN2");
	//table.addRow("STAN1", "#", "0", "L", "STAN2");
	//table.addRow("STAN1", "#", "0", "L", "STAN2");
	//table.addRow("STAN1", "#", "0", "L", "STAN2");
  popup = PopupPtr(new Popup(&state_map));
	end();
    show();
}
Application::~Application( void)
{

}


void Application::new_machine( Fl_Widget* e, void*)
{
	Fl_Menu_Bar* btn = dynamic_cast<Fl_Menu_Bar*>(e);
    Application* app = dynamic_cast<Application*>(btn->parent());
    app->state_map.clear();
}
void Application::open_machine( Fl_Widget*, void* )
{
	Fl_File_Chooser *fc;
	fc->filename_label = "Nazwa pliku:";
	fc->show_label = "Pokazuj:";
	fc->all_files_label = "Wszystkie pliki (*)";
	fc->custom_filter_label = "Wlasny filtr";
	fc->add_favorites_label = "Dodaj do ulubionych";
	fc->favorites_label = "Ulubione";
	fc->manage_favorites_label = "Zarzadzaj ulubionymi";
	fc->filesystems_label = "Moj komputer";
	fl_cancel="Anuluj";

	fc = new Fl_File_Chooser( "c:\\", "*.tur",
	Fl_File_Chooser::SINGLE, "Otwieranie maszyny" );
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
{
	std::cout<<pathname;
	std::string s;
	std::ifstream file( pathname );
	while( true )
	{
		std::getline( file, s );
		send_order_Ffile(s);
		if( file.eof() ) break;
	}
	file.close();

	fl_message_title("Otwieranie pliku");
	fl_close="Zamknij";
	fl_message("Otwieranie pliku powiodlo sie");
}
}

void Application::send_order_Ffile(std::string order)
{
	// std::string converter;
	// int whichField=0;
	// Move anotherMove;
	// state_type beg_State;
	// sym_type RSym;

	// for(int i=0;i<order.size();i++)
	// {
	// 	if(order[i]!=' ')
	// 		converter+=order[i];
	// 	else
	// 	{
	// 		whichField++;
	// 		switch(whichField)
	// 		{
	// 			case 1: beg_State=converter;
	// 			case 2: RSym=converter[0];
	// 			case 3: anotherMove.sym=converter[0];
	// 			case 4: anotherMove.move=converter[0]=='L'?move_left:move_right;
	// 			case 5: break;
	// 		}
	// 		converter="";
	// 	}
	// }
	// anotherMove.state=converter;
	// Application::state_map.put(beg_State, RSym, anotherMove);
}


void Application::save_machine( Fl_Widget*, void* )
{
	Fl_File_Chooser *fc;
	fc->filename_label = "Nazwa pliku:";
	fc->show_label = "Pokazuj:";
	fc->all_files_label = "Wszystkie pliki (*)";
	fc->custom_filter_label = "Wlasny filtr";
	fc->add_favorites_label = "Dodaj do ulubionych";
	fc->favorites_label = "Ulubione";
	fc->manage_favorites_label = "Zarzadzaj ulubionymi";
	fc->filesystems_label = "Moj komputer";
	fl_cancel="Anuluj";

	fc = new Fl_File_Chooser( "c:\\", "*",
	Fl_File_Chooser::CREATE, "Zapisywanie maszyny" );
	fc->preview( 0 );
	fc->ok_label( "Zapisz" );
	fc->previewButton->hide();
	fc->newButton->hide();
	fc->callback( save_tur );
	fc->show();
}

void Application::save_tur( Fl_File_Chooser* e, void *v )
{
	Fl_File_Chooser* btn = dynamic_cast<Fl_File_Chooser*>(e);
//    Application* app = dynamic_cast<Application*>(btn->parent());
   // app->popup->show();

	std::string pathname;
	pathname=e->value();
//if( !o->visible() )
	pathname+=".tur";
	std::ofstream plik( pathname );
	if( plik.is_open() )
	{
	//state_map.put();
		plik << "Napis\n" << "inny" << std::endl;
		plik << 12;
		plik.close();
	}
	else
		std::cout << "Nieudane otwarcie pliku." << std::endl;
	fl_message_title("Zapis do pliku");
	fl_close="Zamknij";
	fl_message("Zapis do pliku udal sie");
}


void Application::show_information( Fl_Widget*, void* )
{
	fl_message_title("Informacje o programie");
	fl_close="Zamknij";
	fl_message("Aktualna wersja programu:1.0.0 \n\nProgram MaszynaTuringa zostal opracowany przez Michala Muskale "
		"oraz Kamila Kryusa \nna potrzeby projektu szkolnego. By dowiedziec sie wiecej porozmawiaj z autorami programu.");
}
void Application::exit( Fl_Widget* e )
{
	((Fl_Widget*) e)->parent()->hide();
}


void Application::add_button(Fl_Widget* e, void*)
{
    Fl_Button* btn = dynamic_cast<Fl_Button*>(e);
    Application* app = dynamic_cast<Application*>(btn->parent());
    app->popup->show();
}
