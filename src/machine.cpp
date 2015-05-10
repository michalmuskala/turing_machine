#include "machine.hpp"

#include <sstream>
#include <algorithm>

namespace machine {

const Move Move::empty = {0};

bool Move::operator==(const Move& other) const {
    return sym == other.sym && state == other.state && move == other.move;
}

void SymMap::put(const sym_type& sym, const Move& move) {
    map_[sym] = move;
}

const Move& SymMap::get(const sym_type& sym) const {
    map_type::const_iterator it = map_.find(sym);

    if (it == map_.end()) {
        return Move::empty;
    } else {
        return it->second;
    }
}

void StateMap::put(const state_type& state, const sym_type& sym, const Move& move) {
    map_[state].put(sym, move);
}

const Move& StateMap::get(const state_type& state, const sym_type& sym) const {
    map_type::const_iterator it = map_.find(state);

    if (it == map_.end()) {
        return Move::empty;
    } else {
        return it->second.get(sym);
    }
}

bool Machine::parse(std::istream& in) {
    std::string line;

    for (std::getline(in, line); in.good(); std::getline(in, line)) {
        std::istringstream line_stream(line + " |");
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
    }

    return true;
}

void Machine::handle(const state_type& state, const sym_type sym) {
    const Move& move = state_map_.get(state, sym);

    if (move == Move::empty) {
        state_ = error_state;
        return;
    }

    strip_[current_] = move.sym;
    state_ = move.state;

    switch (move.move) {
    case move_left:
        if (current_ == 0) {
            strip_.push_front(empty_sym);
        } else {
            --current_;
        }
        break;
    case move_right:
        if (current_ == strip_.size()) {
            strip_.push_back(empty_sym);
            ++current_;
        } else {
            ++current_;
        }
    }
}

const state_type Machine::run() {
    std::cerr << "START " << strip_[current_] << std::endl;
    handle(start_state, strip_[current_]);

    while (state_ != halt_state && state_ != error_state) {
        std::cerr << state_ << " " << strip_[current_] << std::endl;
        handle(state_, strip_[current_]);
    }

    return state_;
}
}
