#ifndef TURING_MACHINE_MENU
#define TURING_MACHINE_MENU

#include <memory>

#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_File_Chooser.H>

class Controller;

class Menu : public Fl_Menu_Bar {
public:
    typedef std::unique_ptr<Fl_File_Chooser> FileChooserPtr;

    Menu(Controller* ctrl);

    static void open_save_machine(Fl_Widget*, void*);
    static void save_machine(Fl_File_Chooser*, void*);

    static void open_load_machine(Fl_Widget*, void*);
    static void load_machine(Fl_File_Chooser*, void*);

    static void new_machine(Fl_Widget*, void*);
    static void show_information(Fl_Widget*, void*);
    static void end_program(Fl_Widget*, void*);

private:
    Controller* ctrl_;
    FileChooserPtr save_;
    FileChooserPtr open_;
};


#endif
