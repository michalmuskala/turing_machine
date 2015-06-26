#ifndef TURING_MACHINE_STATE_MAP
#define TURING_MACHINE_STATE_MAP

#include <map>

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
    typedef map_type::iterator iterator;
    typedef map_type::const_iterator const_iterator;

    void put(const sym_type& sym, const Move& move);
    const Move& get(const sym_type& sym) const;

    inline const_iterator begin() const { return map_.begin(); }
    inline const_iterator end() const { return map_.end(); }
    inline iterator begin() { return map_.begin(); }
    inline iterator end() { return map_.end(); }

  private:
    map_type map_;
};

class StateMap {
  public:
    typedef std::map<state_type, SymMap> map_type;
    typedef map_type::iterator iterator;
    typedef map_type::const_iterator const_iterator;

    void put(const state_type& state, const sym_type& sym, const Move& move);
    const Move& get(const state_type& state, const sym_type& sym) const;

    inline const_iterator begin() const { return map_.begin(); }
    inline const_iterator end() const { return map_.end(); }
    inline iterator begin() { return map_.begin(); }
    inline iterator end() { return map_.end(); }

  private:
    map_type map_;
};

#endif
