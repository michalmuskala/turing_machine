#ifndef TURING_MACHINE_POPUP
#define TURING_MACHINE_POPUP

#include <memory>

#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>

class Controller;

class Popup : public Fl_Window {
public:
    typedef std::unique_ptr<Fl_Box> BoxPtr;
    typedef std::unique_ptr<Fl_Input> InputPtr;
    typedef std::unique_ptr<Fl_Button> ButtonPtr;

    Popup(Controller* ctrl);

    static void add_entry(Fl_Widget*, void*);
private:
    Controller* ctrl_;

    InputPtr state1_;
    InputPtr sym1_;
    InputPtr sym2_;
    InputPtr dir_;
    InputPtr state2_;

    BoxPtr state1_text_;
    BoxPtr sym1_text_;
    BoxPtr sym2_text_;
    BoxPtr dir_text_;
    BoxPtr state2_text_;

    ButtonPtr btn_;
};

#endif
