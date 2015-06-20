#include <FL/Fl_Menu_Bar.H>

class Menu: public Fl_Menu_Bar{
public:
	Menu(int w, int h);

private:
	int w_, h_;
}

