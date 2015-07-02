#ifndef TURING_MACHINE_CONTROLLER
#define TURING_MACHINE_CONTROLLER

#include "application.hpp"
#include "state_map.hpp"
#include "machine.hpp"

class Controller {
public:
    Controller();

    void save_machine(const std::string& path);
    void load_machine(const std::string& path);
    void new_machine();
    void end_program();
    bool add_entry(const std::string& command);
    void start();

private:
    Application app_;
    StateMap state_map_;
    Machine machine_;
};

#endif
