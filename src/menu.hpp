#ifndef TURING_MACHINE_MENU
#define TURING_MACHINE_MENU

#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_File_Chooser.H>

#include <memory>

// Foreword declare Application
class Application;

class Menu: public Fl_Menu_Bar {
public:
    typedef std::unique_ptr<Fl_File_Chooser> FileChooserPtr;

    Menu(Application* app);

    static void open_save_machine(Fl_Widget*, void*);
    static void save_machine(Fl_File_Chooser*, void*);

private:
    Application* app_;
    FileChooserPtr save_;
    FileChooserPtr open_;
};


#endif
