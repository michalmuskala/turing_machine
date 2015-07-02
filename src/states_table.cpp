#include "states_table.hpp"
#include "controller.hpp"

#include <FL/fl_draw.H>

#include <iostream>
// #include <FL/Fl_Box.H>

const StatesTable::row_type StatesTable::headers =
  {"STAN", "SYMBOL", "NOWY SYMBOL", "KIERUNEK", "NOWY STAN"};

StatesTable::StatesTable(Controller* ctrl):
    Fl_Table_Row(12, 170, 572, 500, nullptr), ctrl_(ctrl) {

    // row_height_all(40);
    // col_width_all(200);
    // row_header_width(800);
    cols(headers.size());
    col_header(1);
    col_header_height(50);
    col_width_all(114);
    // col_resize(4);

    end();
}

void StatesTable::refresh(const StateMap& state_map) {
    table_.clear();

    for (auto i = state_map.begin(); i != state_map.end(); ++i) {
        auto sym_map = i->second;

        for (auto j = sym_map.begin(); j != sym_map.end(); ++j) {
            auto action = j->second;
            row_type row;
            row.push_back(i->first);
            row.push_back(j->first);
            row.push_back(action.sym);
            switch (action.move) {
            case move_right:
                row.push_back("PRAWO");
                break;
            case move_left:
                row.push_back("LEWO");
                break;
            }
            row.push_back(action.state);

            table_.push_back(row);
        }
    }

    rows(table_.size());
}

void StatesTable::draw_cell(TableContext context, int R, int C, int X, int Y, int W, int H) {

    switch (context) {
    case CONTEXT_STARTPAGE:
        fl_font(FL_TIMES, 12);
        return;
    case CONTEXT_ROW_HEADER:
    case CONTEXT_COL_HEADER:
        fl_push_clip(X, Y, W, H);

        fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, color());
        fl_color(FL_BLACK);
        fl_draw(headers[C].c_str(), X, Y,W, H, FL_ALIGN_CENTER);

        fl_pop_clip();
        break;

    case CONTEXT_CELL:
        fl_push_clip(X, Y, W, H);

        fl_color( FL_BACKGROUND_COLOR);
        fl_rectf(X, Y, W, H);

        fl_color(FL_BLACK);

        fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, color());
        fl_color(FL_BLACK);
        fl_draw(table_[R][C].c_str(), X, Y, W, H, FL_ALIGN_CENTER);

        fl_pop_clip();
        break;
    }
}
