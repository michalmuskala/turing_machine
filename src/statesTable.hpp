#ifndef TURING_MACHINE_STATES_TABLE
#define TURING_MACHINE_STATES_TABLE

#include <vector>
#include <string>

class statesTable
{
public:
	statesTable();
	
	void addOrder(std::string order);
	void addRow(char*,char*, char*, char*, char*);
	int height;
	
private:

	std::vector<std::string> begin_state;
	std::vector<std::string> end_state;
	std::vector<char> read;
	std::vector<char> write;
	std::vector<char> direction;
	
	
};

#endif
