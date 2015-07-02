#include "machine.hpp"

#include <sstream>
#include <algorithm>
#include <string>

Machine::Machine(const StateMap& state_map): state_map_(state_map) {}

void Machine::initialize(const std::string& strip) {
    current_ = 0;
    state_ = start_state;
    strip_.clear();
    std::copy(strip.begin(), strip.end(), strip_.begin());

    if (strip_.empty()) {
        strip_.push_back(empty_sym);
    }
}

bool Machine::tick() {
    const Move& move = state_map_.get(state_, sym());

    if (move == Move::empty) {
        state_ = error_state;
        return false;
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
        if (current_ == strip_.size() - 1) {
            strip_.push_back(empty_sym);
            ++current_;
        } else {
            ++current_;
        }
    }

    return state_ != halt_state && state_ != error_state;
}

std::string Machine::tape() {
    std::string tape;
    for (auto i = strip_.begin(); i != strip_.end(); ++i) {
        tape += *i;
    }
    return tape;
}
