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
#include "state_map.hpp"
#include "popup.hpp"
#include "menu.hpp"


class Application: public Fl_Window{
public:
    typedef std::unique_ptr<Fl_Box> BoxPtr;
    typedef std::unique_ptr<Fl_Button> ButtonPtr;
    typedef std::unique_ptr<Popup> PopupPtr;
    typedef std::unique_ptr<Menu> MenuPtr;

    Application(int w, int h);
    ~Application( void );

	static void add_button(Fl_Widget*, void*);

    void save_machine( const std::string& path);
	void open_machine( const std::string& path);

	static void Application::clir(Application*);

private:
    int w_, h_;
    StateMap state_map;
    MenuPtr menu_;

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
