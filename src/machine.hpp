#ifndef TURING_MACHINE_MACHINE
#define TURING_MACHINE_MACHINE

#include <deque>
#include <iostream>
#include <functional>

#include "state_map.hpp"

class Machine {
  public:
    typedef std::deque<sym_type> strip_type;
    typedef size_t size_type;

    Machine(const StateMap& state_map);
    void initialize(const std::string& strip = "");
    bool tick();
    inline const state_type& state() const { return state_; }
    inline sym_type sym() const { return strip_[current_]; }

    std::string tape();
    inline size_t pos() { return current_; }

  private:
    const StateMap& state_map_;
    size_type current_;
    state_type state_;
    strip_type strip_;
};

#endif
