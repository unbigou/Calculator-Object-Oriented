#include "../../../interface/Calculator.hpp"
#include "../Keyboard_PHG.hpp"

class KeyDigit_PHG: public KeyDigit 
{
	private:
		Keyboard* keyboard;
		Symbol symbol;
		Digit digit;
    public:
		KeyDigit_PHG(Symbol, Digit);

		void setKeyboard(Keyboard*);
		void press();
        Digit getDigit();
		Symbol getSymbol();
};