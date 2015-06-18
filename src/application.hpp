#include <FL/Fl_Window.H>

class Application: public Fl_Window {
public:
    Application(int w, int h);

private:
    int w_, h_;
};
