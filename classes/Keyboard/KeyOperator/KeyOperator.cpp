#include "./KeyOperator.hpp"
#include <stdio.h>

KeyOperator_PHG::KeyOperator_PHG(Symbol symbol, Operator op)
{
	this-> symbol = symbol;
	this-> op = op;
}


void KeyOperator_PHG::setKeyboard(Keyboard* keyboard)
{
	this-> keyboard = keyboard;
}


void KeyOperator_PHG::press()
{
	if (this-> keyboard != NULL)
	{
		this-> keyboard-> receive(this-> op);
	}
}


Operator KeyOperator_PHG::getOperator()
{
	return this-> op;
}


Symbol KeyOperator_PHG::getSymbol()
{
	return this-> symbol;
}