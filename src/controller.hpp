#ifndef TURING_MACHINE_CONTROLLER
#define TURING_MACHINE_CONTROLLER

#include "application.hpp"
#include "state_map.hpp"

class Controller {
public:
    Controller();

    void save_machine(const std::string& path);
    void load_machine(const std::string& path);
    void new_machine();
    void end_program();
    bool add_entry(const std::string& command);

private:
    Application app_;
    StateMap state_map_;
};

#endif
