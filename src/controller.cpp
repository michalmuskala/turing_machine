#include "controller.hpp"

#include <FL/Fl.H>

#include <fstream>
#include <iostream>
#include <sstream>

Controller::Controller(): app_(this), state_map_(), machine_(state_map_) {
    state_map_.put("START", "0", Move::empty);
    state_map_.put("START2323232", "0", Move::empty);
    state_map_.put("START33333", "0", Move::empty);

    app_.refresh_state(state_map_);
    app_.refresh_tape("", "", 0);
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
                std::string move;
                switch(j->second.move) {
                case move_left: move = "L"; break;
                case move_right: move = "P"; break;
                }
                plik << i->first <<
                    " " << j->first << " "
                     << j->second.sym << " " << move << " "
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
    app_.refresh_state(state_map_);
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
        return false;
    }

    if (raw_move == 'L' || raw_move == 'l') {
        move = move_left;
    } else if (raw_move == 'R' || raw_move == 'r' || raw_move == 'P' || raw_move == 'p') {
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

    app_.refresh_state(state_map_);
    app_.refresh_tape("", "", 0);

    return true;
}

void Controller::start() {
    machine_.initialize();

    app_.refresh_tape(start_state, "", 0);

    while (machine_.tick()) {
        Fl::wait(1);
        app_.refresh_tape(machine_.state(), machine_.tape(), machine_.pos());
    }
    Fl::wait(1);

    app_.refresh_tape(machine_.state(), machine_.tape(), machine_.pos());
}
