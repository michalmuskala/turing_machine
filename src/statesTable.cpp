#include "statesTable.hpp"
#include <iostream>


void statesTable::addOrder(std::string order)
{
	int whichField=-1;
	char symbol;
	int i=0;
	for(;i<order.size();i++)
	{
		if(order[i]!=' ')
			symbol=order[i];
		else
		{
			whichField++;
			switch(whichField)
			{
				case 0: begin_state.push_back(symbol -'0'); break; 
				case 1: read.push_back(symbol); break;
				case 2: write.push_back(symbol);  break;
				case 3: direction.push_back(symbol);  break;
			}
		}			
	}
	end_state.push_back(symbol - '0');
}