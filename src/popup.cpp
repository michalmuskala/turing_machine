#include "popup.hpp"
#include "controller.hpp"

#include <string>

Popup::Popup(Controller* ctrl):
    Fl_Window(300, 400, "Dodaj rozkaz"), ctrl_(ctrl) {

    state1_ = InputPtr(new Fl_Input(110, 30, 180, 17, "Stan poczatkowy: "));
    state1_->value("");
    state1_->labelsize(11);
    state1_->textsize(11);

    state1_text_ = BoxPtr(new Fl_Box(10,50,280,50,"Stan, w jakim maszyna sie znajduje przed \nrozpoczeciem pracy (np.: 'STAN1')."));
    state1_text_->labelsize(11);

    sym1_ = InputPtr(new Fl_Input(110, 100, 180, 17, "Czytany symbol:"));
    sym1_->value("");
    sym1_->labelsize(11);
    sym1_->textsize(11);
    sym1_->maximum_size(1);

    sym1_text_ = BoxPtr(new Fl_Box(10,115,280,50,"Symbol, ktory bedzie przeczytany z tasmy (np.: '#')."));
    sym1_text_->labelsize(11);

    sym2_ = InputPtr(new Fl_Input(110, 165, 180, 17, "Zapisany symbol:"));
    sym2_->value("");
    sym2_->labelsize(11);
    sym2_->textsize(11);
    sym2_->maximum_size(1);

    sym2_text_ = BoxPtr(new Fl_Box(10,175,280,50,"Symbol, ktory bedzie zapisany do tasmy (np.: '1')."));
    sym2_text_->labelsize(11);

    dir_ = InputPtr(new Fl_Input(110, 230, 180, 17, "Kierunek:"));
    dir_->value("");
    dir_->labelsize(11);
    dir_->textsize(11);
    dir_->maximum_size(1);

    dir_text_ = BoxPtr(new Fl_Box(10,240,280,50,"Kierunek nastepnego ruchu glowicy (L lub P)."));
    dir_text_->labelsize(11);

    state2_ = InputPtr(new Fl_Input(110, 295, 180, 17, "Stan koncowy:"));
    state2_->value("");
    state2_->labelsize(11);
    state2_->textsize(11);

    state2_text_ = BoxPtr(new Fl_Box(10,305,280,50,"Stan maszyny, w jakim sie znajdzie \npo wykonaniu rozkazu (np.: 'STAN2')."));
    state2_text_->labelsize(11);


    btn_ = ButtonPtr(new Fl_Button(230, 350, 50, 30, "Dodaj"));
    btn_->callback(add_entry, ctrl_);

    end();
}

void Popup::add_entry(Fl_Widget* btn, void* raw_ctrl) {
    Popup* popup = dynamic_cast<Popup*>(btn->parent());
    Controller* ctrl = static_cast<Controller*>(raw_ctrl);

    std::string command;
    command += popup->state1_->value();
    command += " ";
    command += popup->sym1_->value();
    command += " ";
    command += popup->sym2_->value();
    command += " ";
    command += popup->dir_->value();
    command += " ";
    command += popup->state2_->value();

    if (ctrl->add_entry(command)) {
        popup->hide();
    } else {
        fl_message("Nieporawna komenda");
    }
}

