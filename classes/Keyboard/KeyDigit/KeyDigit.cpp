#include "./KeyDigit.hpp"
#include <stdio.h>

KeyDigit_PHG::KeyDigit_PHG(Symbol symbol, Digit digit)
{
	this-> symbol = symbol;
	this-> digit = digit;
}


void KeyDigit_PHG::setKeyboard(Keyboard* keyboard)
{
	this-> keyboard = keyboard;
}


void KeyDigit_PHG::press()
{
	if( this-> keyboard != NULL)
	{
		this-> keyboard-> receive(this-> digit);
	}
}


Digit KeyDigit_PHG::getDigit()
{
	return this-> digit;
}


Symbol KeyDigit_PHG::getSymbol()
{
	return this-> symbol;
}