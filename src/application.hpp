#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Draw.H>
#include <FL/Fl_BMP_Image.H>
#include <FL/Fl_Box.H>


class Application: public Fl_Window{
public:
    Application(int w, int h);
	~Application( void );


	static void new_machine( Fl_Widget*, void* );
	static void open_machine( Fl_Widget*, void* );
	static void save_machine( Fl_Widget*, void* );
	static void show_information( Fl_Widget*, void* );
	static void exit( Fl_Widget* );

	static void open_tur( Fl_File_Chooser* o, void *v );
	static void add_button(Fl_Widget*, void*);
	
private:
    int w_, h_;
	Fl_Menu_Bar *menu_Bar;
	Fl_Box *box;
	Fl_Box *tape;
	Fl_Box *service;

	Fl_Button *add;
	Fl_Button *start;

	Fl_Box *state_beg;
	Fl_Box *read_sym;
	Fl_Box *write_sym;
	Fl_Box *dir;
	Fl_Box *state_end;
};
