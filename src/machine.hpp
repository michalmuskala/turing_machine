#ifndef TURING_MACHINE_MACHINE
#define TURING_MACHINE_MACHINE

#include <deque>
#include <iostream>
#include <functional>

#include "state_map.hpp"

class Machine {
  public:
    typedef std::function<void(const state_type&, const sym_type)> callback_type;

    Machine(const StateMap& state_map);
    bool parse(std::istream& in);
    const state_type run(const std::string& strip = "");
    void register_callback(callback_type& callback);

  private:
    StateMap state_map_;
    callback_type& callback_;
};

#endif
