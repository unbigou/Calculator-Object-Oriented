#include "./KeyControl.hpp"
#include <stdio.h>

KeyControl_PHG::KeyControl_PHG(Symbol symbol, Control control)
{
	this-> symbol = symbol;
	this-> control = control;
}


void KeyControl_PHG::setKeyboard(Keyboard* keyboard)
{
	this-> keyboard = keyboard;
}


void KeyControl_PHG::press()
{
	if (this-> keyboard != NULL)
	{
		this-> keyboard-> receive(this-> control);
	}
}


Control KeyControl_PHG::getControl()
{
	return this-> control;
}


Symbol KeyControl_PHG::getSymbol()
{
	return this-> symbol;
}