#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>

class Application: public Fl_Window{
public:
    Application(int w, int h);
	~Application( void );


	static void new_machine( Fl_Widget*, void* );
	static void open_machine( Fl_Widget*, void* );
	static void save_machine( Fl_Widget*, void* );
	static void show_information( Fl_Widget*, void* );
	static void exit( Fl_Widget*, void* );

private:
    int w_, h_;


	Fl_Menu_Bar *menu_Bar;
};

