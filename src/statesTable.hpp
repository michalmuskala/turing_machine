#include <vector>
#include <string>

class statesTable
{
public:

	void addOrder(std::string order);
private:

	std::vector<int> begin_state;
	std::vector<int> end_state;
	std::vector<char> read;
	std::vector<char> write;
	std::vector<char> direction;
};
