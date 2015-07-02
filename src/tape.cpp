#include "tape.hpp"
#include "controller.hpp"

#include <iostream>
#include <FL/fl_draw.H>

Tape::Tape(Controller* ctrl): Fl_Box(-1, 61, 603, 30, "TAPE"), ctrl_(ctrl) {
    box(FL_UP_BOX);
}

void Tape::draw() {
    Fl_Box::draw();

    fl_push_clip(0, 30, 602, 40);

    std::string str;
    for (int i = 0; i < 25; ++i) {
        fl_draw_box(FL_THIN_UP_BOX, i * 24, 20, 24, 40, color());
        fl_color(FL_BLACK);
        str = tape_[i];
        fl_draw(str.c_str(), i * 24, 25, 24, 40, FL_ALIGN_CENTER);
    }

    fl_pop_clip();
}

void Tape::refresh(const std::string& strip, const size_t pos) {
    tape_ = "";
    int start = pos - 12;
    while (start++ < 0) {
        tape_ += '#';
    }
    tape_ += strip;
    while (tape_.length() < 25) {
        tape_ += '#';
    }
}
