#include "statesTable.hpp"
#include <iostream>
#include <FL/Fl_Box.H>


void statesTable::addRow()
{

	int height=170;
	Fl_Box *state_beg, *read_sym, *write_sym, *dir, *state_end;
	for (auto i = state_map_->begin(); i != state_map_->end(); ++i)
	{
		for (auto j = i->second.begin(); j != i->second.end(); ++j)
		{
			state_beg = new Fl_Box(12,height+34, 125,35,i->first.c_str());
			state_beg->box(FL_BORDER_BOX);

			read_sym = new Fl_Box(136,statesTable::height+34, 145,35, j->first.c_str());
			read_sym->box(FL_BORDER_BOX);

			write_sym = new Fl_Box(280,height+34, 125,35, j->second.sym.c_str());
			write_sym->box(FL_BORDER_BOX);

			const char* conv="LEWO";
			if(j->second.move)
				conv="PRAWO";
			dir = new Fl_Box(404,height+34, 75,35, conv);
			dir->box(FL_BORDER_BOX);

			state_end = new Fl_Box(478,height+34, 105,35,j->second.state.c_str());
			state_end->box(FL_BORDER_BOX);
			std::cout<<std::endl<<i->first.c_str()<<" "<<j->first.c_str()<<" "<<j->second.sym.c_str()<<" "<<conv<<" "<<j->second.state.c_str()<<std::endl;

			height+=34;
		}
	}
}

/*
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
}*/


	const char* text="Stan poczatkowy";
	static int which_row=0;
void statesTable::draw_cell(TableContext context, 
			  int R, int C, int X, int Y, int W, int H)
{
    static char s[40];

	//rows_();
	//rows(5);
   sprintf(s, "%s", text);		// text for each cell

    switch ( context )
    {
	case CONTEXT_STARTPAGE:
	    //fl_font(FL_TIMES, 12);
	    return;

	case CONTEXT_COL_HEADER:
	    fl_push_clip(X, Y, W, H);
	    {
			fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, color());
			fl_color(FL_BLACK);
			fl_draw(s, X, Y,W, H, FL_ALIGN_CENTER);
			
			//if(C==0)
				//siema="Stan poczatkowy";
			//else
				if(C==0)
				text="Przeczytany symbol";
			else if(C==1)
				text="Wpisany symbol";
			else if(C==2)
				text="Kierunek";
			else if(C==3)
				text="Stan koncowy";
			sprintf(s, "%s", text);	
		}
	    fl_pop_clip();
	    return;

	case CONTEXT_CELL:
	{
		//sprintf(s, "%d", R+C);
	    //fl_push_clip(X, Y, W, H);
	    {
	        // BG COLOR
		fl_color( FL_BACKGROUND_COLOR);
		fl_rectf(X, Y, W, H);

		// TEXT
		fl_color(FL_BLACK);
		fl_draw(s, X, Y, W, H, FL_ALIGN_CENTER);

		// BORDER
		fl_color(FL_BLACK); 
		fl_rect(X, Y, W, H);
		fl_push_clip(X, Y, W, H);
		for (auto i = state_map_->begin(); i != state_map_->end(); ++i)
		{
			for (auto j = i->second.begin(); j != i->second.end(); ++j)
			{
				text=i->first.c_str();
				if(C==0)
					text=j->first.c_str();
				
				else if(C==1)
					text=j->second.sym.c_str();
				else if(C==2)
				{
					text="LEWO";
					if(j->second.move)
						text="PRAWO";		
				}
				else if(C==3)
					text=j->second.state.c_str();
			
				 sprintf(s, "%s", text);
			}
		}	
	    }
	    fl_pop_clip();
	    return;
	}

	default:
	    return;
    }
}