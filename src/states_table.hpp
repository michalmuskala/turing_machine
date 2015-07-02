#ifndef TURING_MACHINE_STATES_TABLE
#define TURING_MACHINE_STATES_TABLE

#include <vector>
#include <string>
#include <FL/Fl_Table_Row.H>

#include "state_map.hpp"

// Foreward declare app
class Controller;

class StatesTable : public Fl_Table_Row {
public:
    typedef std::string cell_type;
    typedef std::vector<cell_type> row_type;
    typedef std::vector<row_type> table_type;

    StatesTable(Controller* app);

    void refresh(const StateMap& state_map);

private:
    static const row_type headers;

    void draw_cell(TableContext context, int R, int C, int X, int Y, int W, int H);

    Controller* ctrl_;
    table_type table_;
};

#endif
