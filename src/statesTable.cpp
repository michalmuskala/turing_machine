#include "statesTable.hpp"
#include <iostream>
#include <FL/Fl_Box.H>

void statesTable::addOrder(std::string order)
{
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
				case 0: begin_state.push_back(symbol); break; 
				case 1: read.push_back(symbol[0]); break;
				case 2: write.push_back(symbol[0]);  break;
				case 3: direction.push_back(symbol[0]);  break;
				case 4: break;
			}
			symbol="";
		}			
	}
	end_state.push_back(symbol);
}

void statesTable::addRow()
{
	Fl_Box *state_beg, *read_sym, *write_sym, *dir, *state_end;

	for (auto i = state_map_->begin(); i != state_map_->end(); ++i)
	{
		for (auto j = i->second.begin(); j != i->second.end(); ++j)
		{
			state_beg = new Fl_Box(12,height+34, 125,35,i->first.c_str());
			state_beg->box(FL_BORDER_BOX);

			read_sym = new Fl_Box(136,statesTable::height+34, 145,35, j->first.c_str());
			//read_sym->box(FL_BORDER_BOX);
			//write_sym = new Fl_Box(280,height+34, 125,35, j->second.sym);
			//write_sym->box(FL_BORDER_BOX);
			const char* conv="LEWO";
			if(j->second.move)
				conv="PRAWO";
			dir = new Fl_Box(404,height+34, 75,35, conv);
			dir->box(FL_BORDER_BOX);
			state_end = new Fl_Box(478,height+34, 105,35,j->second.state.c_str());
			state_end->box(FL_BORDER_BOX);
			height+=34;
		}
	}

	
	
}
statesTable::statesTable(StateMap* state_map): state_map_(state_map)
{
	Fl_Box *state_beg, *read_sym, *write_sym, *dir, *state_end;
	state_beg = new Fl_Box(12,170, 125,35,"Stan poczatkowy");
	state_beg->box(FL_BORDER_BOX);
	read_sym = new Fl_Box(136,170, 145,35,"Przeczytany symbol");
	read_sym->box(FL_BORDER_BOX);
	write_sym = new Fl_Box(280,170, 125,35,"Wpisany symbol");
	write_sym->box(FL_BORDER_BOX);
	dir = new Fl_Box(404,170, 75,35,"Kierunek");
	dir->box(FL_BORDER_BOX);
	state_end = new Fl_Box(478,170, 105,35,"Stan koncowy");
	state_end->box(FL_BORDER_BOX);
	height=170;
}
