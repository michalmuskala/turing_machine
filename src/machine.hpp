#include <deque>
#include <string>
#include <map>
#include <iostream>

namespace machine {

typedef char sym_type;
typedef std::string state_type;
typedef enum {move_left, move_right} move_type;

const sym_type empty_sym = '#';
const state_type start_state = "START";
const state_type halt_state = "HALT";
const state_type error_state = "ERROR";

struct Move {
    sym_type sym;
    state_type state;
    move_type move;

    static const Move empty;

    bool operator==(const Move& other) const;
};

class SymMap {
  public:
    typedef std::map<sym_type, Move> map_type;

    void put(const sym_type& sym, const Move& move);
    const Move& get(const sym_type& sym) const;
  private:
    map_type map_;
};

class StateMap {
  public:
    typedef std::map<state_type, SymMap> map_type;

    void put(const state_type& state, const sym_type& sym, const Move& move);
    const Move& get(const state_type& state, const sym_type& sym) const;
  private:
    map_type map_;
};

class Machine {
  public:
    typedef std::deque<sym_type> strip_type;
    typedef size_t size_type;

    template <typename T>
    explicit Machine(const T& strip, const size_type current = 0):
        current_(current) {
        std::copy(strip.begin(), strip.end(), strip_.begin());

        if (strip_.empty()) {
            strip_.push_back(empty_sym);
        }
    }

    Machine(): current_(0) {
        strip_.push_back(empty_sym);
    }

    bool parse(std::istream& in);
    const state_type run();

  private:
    strip_type strip_;
    size_type current_;
    state_type state_;
    StateMap state_map_;

    void handle(const state_type& state, const sym_type sym);
};

}
