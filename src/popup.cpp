#include "popup.hpp"
#include <iostream>


Fl_Input *inputBegState, *inputRSym, *inputWSym, *inputDir, *inputEndState;
Fl_Box *begText, *rSymText, *wSymText, *dirText, *endText;
Popup::Popup(StateMap* state_map, statesTable* table): Fl_Window(300, 400, "Dodaj rozkaz"), state_map_(state_map), table_(table) {

	inputBegState = new Fl_Input(110, 30, 180, 17, "Stan poczatkowy: ");
	inputBegState->value("");
	inputBegState->labelsize(11);
	inputBegState->textsize(11);
  	
	begText = new Fl_Box(10,50,280,50,"Stan, w jakim maszyna sie znajduje przed \nrozpoczeciem pracy (np.: 'STAN1').");
	begText->labelsize(11);
	

	inputRSym = new Fl_Input(110, 100, 180, 17, "Czytany symbol:   ");
	inputRSym -> value("");
	inputRSym->labelsize(11);
	inputRSym->textsize(11);
	inputRSym->maximum_size(1);

	rSymText = new Fl_Box(10,115,280,50,"Symbol, ktory bedzie przeczytany z tasmy (np.: '#').");
	rSymText->labelsize(11);

	inputWSym = new Fl_Input(110, 165, 180, 17, "Zapisany symbol:  ");
	inputWSym -> value("");
	inputWSym->labelsize(11);
	inputWSym->textsize(11);
	inputWSym->maximum_size(1);

	wSymText = new Fl_Box(10,175,280,50,"Symbol, ktory bedzie zapisany do tasmy (np.: '1').");
	wSymText->labelsize(11);

	inputDir = new Fl_Input(110, 230, 180, 17, "Kierunek:               ");
	inputDir -> value("");
	inputDir->labelsize(11);
	inputDir->textsize(11);
	inputDir->maximum_size(1);

	dirText = new Fl_Box(10,240,280,50,"Kierunek nastepnego ruchu glowicy (L lub P).");
	dirText->labelsize(11);

	inputEndState = new Fl_Input(110, 295, 180, 17, "Stan koncowy:      ");
	inputEndState -> value("");
	inputEndState->labelsize(11);
	inputEndState->textsize(11);

	endText = new Fl_Box(10,305,280,50,"Stan maszyny, w jakim sie znajdzie \npo wykonaniu rozkazu (np.: 'STAN2').");
	endText->labelsize(11);


	 Fl_Button *addOrder;
	 addOrder = new Fl_Button(230, 350, 50, 30, "Dodaj");
	 addOrder->callback(send_order_input);

     end();
}


void Popup::send_order_input(Fl_Widget* e, void*)
{
	Move anotherMove;
	std::string BegState=inputBegState->value();
	sym_type RSymbol=inputRSym->value();
	anotherMove.sym=inputWSym->value();
	anotherMove.state=inputEndState->value();
	if(inputDir->value()[0]=='L')
		anotherMove.move=move_left;
	else
		anotherMove.move=move_right;
	Fl_Button* btn=dynamic_cast<Fl_Button*>(e);
	Popup* pop = dynamic_cast<Popup*>(btn->parent());
	pop->state_map_->put(BegState, RSymbol, anotherMove);
	pop->table_->rows(pop->state_map_->length());
	pop->hide();
	
}

