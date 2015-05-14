#include <deque>
#include <map>
#include <iostream>
#include <functional>

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
    typedef std::function<void(const state_type&, const sym_type)> callback_type;

    Machine();
    bool parse(std::istream& in);
    const state_type run(const std::string& strip = "");
    void register_callback(callback_type& callback);

  private:
    StateMap state_map_;
    callback_type& callback_;
};

}
