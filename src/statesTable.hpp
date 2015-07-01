#ifndef TURING_MACHINE_STATES_TABLE
#define TURING_MACHINE_STATES_TABLE

#include <vector>
#include <string>
#include "state_map.hpp"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Table_Row.H>
#include <stdio.h>
#include <string.h>
#include <iostream>



class statesTable : public Fl_Table_Row
{
public:
	statesTable(StateMap* state_map);

	statesTable(StateMap* state_map, int x, int y, int w, int h, const char *l=0) : Fl_Table_Row(x,y,w,h,l), state_map_(state_map)
	{ end(); }
    ~statesTable() { }
	
	void addOrder(std::string order);
	void addRow();

	int height;
	
protected:
    void draw_cell(TableContext context, int R=0, int C=0, int X=0, int Y=0, int W=0, int H=0);

private:
    StateMap* state_map_;
};

#endif
