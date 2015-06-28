#include "state_map.hpp"

const Move Move::empty = {empty_sym, error_state, move_right};

bool Move::operator==(const Move& other) const {
    return sym == other.sym && state == other.state && move == other.move;
}

void SymMap::put(const sym_type sym, const Move& move) {
    map_[sym] = move;
}

const Move& SymMap::get(const sym_type sym) const {
    map_type::const_iterator it = map_.find(sym);

    if (it == map_.end()) {
        return Move::empty;
    } else {
        return it->second;
    }
}

void StateMap::put(const state_type& state1, const sym_type sym1, const sym_type sym2, const move_type move, const state_type& state2) {
    Move action = {sym2, state2, move};
    put(state1, sym2, action);
}

void StateMap::put(const state_type& state, const sym_type sym, const Move& move) {
    map_[state].put(sym, move);
}

const Move& StateMap::get(const state_type& state, const sym_type sym) const {
    map_type::const_iterator it = map_.find(state);

    if (it == map_.end()) {
        return Move::empty;
    } else {
        return it->second.get(sym);
    }
}
