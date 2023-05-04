#include "../../../interface/Calculator.hpp"
#include "../Keyboard_PHG.hpp"

class KeyOperator_PHG: public KeyOperator
{	private:
		Keyboard* keyboard;
		Symbol symbol;
		Operator op;
    public:
		KeyOperator_PHG(Symbol, Operator);

		void setKeyboard(Keyboard*);
		void press();
        Operator getOperator();
		Symbol getSymbol();
};