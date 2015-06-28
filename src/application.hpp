#ifndef TURING_MACHINE_APPLICATION
#define TURING_MACHINE_APPLICATION

#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/fl_draw.H>
#include <FL/Fl_BMP_Image.H>
#include <FL/Fl_Box.H>
#include <memory>
#include <FL/Fl_Slider.H>
#include <string>
//#include "machine.hpp"
#include "state_map.hpp"
#include "popup.hpp"


class Application: public Fl_Window{
public:
    typedef std::unique_ptr<Fl_Menu_Bar> MenuBarPtr;
    typedef std::unique_ptr<Fl_Box> BoxPtr;
    typedef std::unique_ptr<Fl_Button> ButtonPtr;
    typedef std::unique_ptr<Popup> PopupPtr;

    Application(int w, int h);
	~Application( void );


	static void new_machine( Fl_Widget*, void* );
	static void open_machine( Fl_Widget*, void* );
	static void save_machine( Fl_Widget*, void* );
	static void show_information( Fl_Widget*, void* );
	static void exit( Fl_Widget* );

	static void open_tur( Fl_File_Chooser* o, void *v );
	static void save_tur( Fl_File_Chooser* o, void *v );
	static void add_button(Fl_Widget*, void*);

	
	static void send_order_Ffile(std::string);

private:
    int w_, h_;
	StateMap state_map;
    MenuBarPtr menu_Bar;

    BoxPtr box;
    BoxPtr tape;
    BoxPtr service;

    ButtonPtr add;
    ButtonPtr start;

    BoxPtr state_beg;
    BoxPtr read_sym;
    BoxPtr write_sym;
    BoxPtr dir;
    BoxPtr state_end;	

    PopupPtr popup;
};


#endif
