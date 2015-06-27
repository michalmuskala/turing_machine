#include "machine.hpp"

#include <sstream>
#include <algorithm>
#include <string>

static Machine::callback_type noop = [](const state_type&, const sym_type) {};

Machine::Machine(): state_map_(), callback_(noop) {}

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

void Machine::register_callback(callback_type& callback) {
    callback_ = callback;
}

class Runner {
  public:
    typedef std::deque<sym_type> strip_type;
    typedef size_t size_type;

    template <class T>
    Runner(const T& strip, const StateMap& state_map):
        current_(0), state_map_(state_map), state_(start_state) {
        std::copy(strip.begin(), strip.end(), strip_.begin());
        if (strip_.empty()) {
            strip_.push_back(empty_sym);
        }
    }

    bool tick();
    inline const state_type& state() const { return state_; }
    inline sym_type sym() const { return strip_[current_]; }

  private:
    size_type current_;
    const StateMap& state_map_;
    state_type state_;
    strip_type strip_;
};

bool Runner::tick() {
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

const state_type Machine::run(const std::string& strip) {
    Runner runner(strip, state_map_);

    callback_(runner.state(), runner.sym());

    while (runner.tick()) {
        callback_(runner.state(), runner.sym());
    }

    return runner.state();
}
