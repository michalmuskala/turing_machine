#include "application.hpp"
#include <iostream>
#include "statesTable.hpp"
#include <string>

#include <fstream>

void rusz_cb( Fl_Widget* o, void* v )
{
double wartosc = ((Fl_Slider* ) o)->value();
/* ... */
}

Application::Application(int w, int h): Fl_Window(w, h, "Maszyna Turinga"),
                                        w_(w), h_(h), state_map() {
    menu_ = MenuPtr(new Menu(this));

	tape = BoxPtr(new Fl_Box(-1, 60+1, w_+3, 30, "TAPE"));
	tape->box(FL_UP_BOX);

	service = BoxPtr(new Fl_Box(-1,90,w_+3,50,"Start, Add, etc."));
	service->box(FL_UP_BOX);

	add = ButtonPtr(new Fl_Button(5, 100, 50, 30, "Dodaj"));
	add->callback(add_button);

	start = ButtonPtr(new Fl_Button(75, 100, 50, 30, "Start"));
//	start->callback(open_machine);
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
void Application::clir(Application *app)
{
	app->state_map.clear();
}

void Application::save_machine(const std::string& path)
{
	std::string pathname=path;
	int position=path.find(".tur");
	if(position==-1)
		pathname+= ".tur";
	std::ofstream plik(pathname);
    if( plik.is_open() )
	{
        for (auto i = state_map.begin(); i != state_map.end(); ++i)
		{
			for (auto j = i->second.begin(); j != i->second.end(); ++j) 
			{
				plik << i->first << 
				" " << j->first << " "
				<< j->second.sym << " " << j->second.move << " "
				<< j->second.state << std::endl;
			}
		}
        plik.close();
    } 
	else
        std::cout << "Nieudane otwarcie pliku." << std::endl;

}

void Application::open_machine( const std::string& path )
{
    std::ifstream plik(path);
	std:: string stateF, stateL, order;
	char symF='0', symL='1', dir='L';
    if( plik.is_open() )
	{
		while(!plik.eof())
		{
			getline( plik, order );
			int whichField=-1;
				std::string symbol;
				int i=0;
				for(;i<order.size();i++)
				{
					if(order[i]!=' ')
						symbol+=order[i];
					else
					{
						whichField++;
						switch(whichField)
						{
							case 0: stateF=symbol; break; 
							case 1: symF=symbol[0]; break;
							case 2: symL=symbol[0]; break;
							case 3: dir=symbol[0];  break;
							case 4: break;
						}
						symbol="";
					}			
				}
				stateL=symbol;
				std::cout<<stateF<<symF<<symL<<dir<<stateL<<std::endl;
				if(dir=='L')
					state_map.put(stateF, symF, symL, move_left , stateL);
				else 
					state_map.put(stateF, symF, symL, move_right , stateL);
        }
        plik.close();
    }
	else
        std::cout << "Nieudane otwarcie pliku." << std::endl;
}

void Application::add_button(Fl_Widget* e, void*)
{
    Fl_Button* btn = dynamic_cast<Fl_Button*>(e);
    Application* app = dynamic_cast<Application*>(btn->parent());
    app->popup->show();
}
