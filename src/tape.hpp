#ifndef TURING_MACHINE_TAPE
#define TURING_MACHINE_TAPE

#include <memory>
#include <string>

#include <FL/Fl_Box.H>

class Controller;

class Tape : public Fl_Box {
public:
    Tape(Controller* ctrl);

    void draw();
    void refresh(const std::string& strip, const size_t pos);

private:
    Controller* ctrl_;
    std::string tape_;
};


#endif
