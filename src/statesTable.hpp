#ifndef TURING_MACHINE_STATES_TABLE
#define TURING_MACHINE_STATES_TABLE

#include <vector>
#include <string>
#include "state_map.hpp"

class statesTable
{
public:
	statesTable(StateMap* state_map);
	
	void addOrder(std::string order);
	void addRow();

	int height;
	
private:

	std::vector<std::string> begin_state;
	std::vector<std::string> end_state;
	std::vector<char> read;
	std::vector<char> write;
	std::vector<char> direction;
	
    StateMap* state_map_;


};

#endif
