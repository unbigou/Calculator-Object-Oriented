#include "../../../interface/Calculator.hpp"
#include "../Keyboard_PHG.hpp"

class KeyControl_PHG: public KeyControl
{
	private:
		Keyboard* keyboard;
		Control control;
		Symbol symbol;
    public:
		KeyControl_PHG(Symbol, Control);

		void setKeyboard(Keyboard*);
		void press();
        Control getControl();
		Symbol getSymbol();
};