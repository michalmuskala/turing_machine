#include "controller.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

Controller::Controller(): app_(this), state_map_() {
    state_map_.put("START", "0", Move::empty);
    state_map_.put("START2323232", "0", Move::empty);
    state_map_.put("START33333", "0", Move::empty);

    app_.refresh(state_map_);
    app_.redraw();
}

void Controller::save_machine(const std::string& path) {
    std::string pathname = path;
    int position = path.find(".tur");
    if(position==-1)
        pathname+= ".tur";

    std::ofstream plik(pathname);

    if(plik.is_open()) {
        for (auto i = state_map_.begin(); i != state_map_.end(); ++i) {
            for (auto j = i->second.begin(); j != i->second.end(); ++j) {
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


void Controller::load_machine(const std::string& path) {
    new_machine();

    std::ifstream plik(path);
    std::string order;
    if( plik.is_open() )
    {
        while(!plik.eof()) {
            getline(plik, order);
            add_entry(order);
        }
    }
	else
        std::cout << "Nieudane otwarcie pliku." << std::endl;
}

void Controller::new_machine() {
    state_map_.clear();
}

void Controller::end_program() {
    app_.hide();
}

bool Controller::add_entry(const std::string& command) {
    std::istringstream line_stream(command + " |");

    state_type state, new_state;
    sym_type sym, new_sym;
    char raw_move;
    move_type move;

    line_stream >> state;
    line_stream >> sym;
    line_stream >> new_sym;
    line_stream >> raw_move;
    line_stream >> new_state;

    if (!line_stream.good()) {
        std::cerr << "Stream was empty" << std::endl;
        return false;
    }

    if (raw_move == 'L' || raw_move == 'l') {
        move = move_left;
    } else if (raw_move == 'R' || raw_move == 'r') {
        move = move_right;
    } else {
        std::cerr << "Invalid move symbol" << std::endl;
        return false;
    }

    std::string sentiel;
    line_stream >> sentiel;
    if (sentiel != "|") {
        std::cerr << "Malformed line, too many tokens" << std::endl;
        return false;
    }

    Move move_struct = {new_sym, new_state, move};

    state_map_.put(state, sym, move_struct);

    app_.refresh(state_map_);

    return true;
}
