#include <iostream>

#include "./Keyboard_PHG.hpp"
#include "../Calculator_Error/CalculatorError_PHG.hpp"


void Keyboard_PHG::receive(Digit digit)
{
	if(this-> cpu)
	{
    	this-> cpu-> receive(digit);
	}
	else
	{
    	std::cerr << "Keyboard without cpu!\n";
	}
};


void Keyboard_PHG::receive(Operator op)
{
	if(this-> cpu)
	{
    	this-> cpu-> receive(op);
	}
	else
	{
    	std::cerr << "Keyboard without cpu!\n";
	}
};


void Keyboard_PHG::receive(Control control)
{
	if(this-> cpu)
	{
    	this-> cpu-> receive(control);
	}
	else
	{
    	std::cerr << "Keyboard without cpu!\n";
	}
};


Key* Keyboard_PHG::getKey(Digit digit)
{
	for (Key *key : this->keys)
	{
		if (dynamic_cast<KeyDigit*>(key) && ((KeyDigit*)key)-> getDigit() == digit)
		{
			return key;
		}
	}
	throw new CalculatorError_PHG("Key with digit not found!");
};


Key* Keyboard_PHG::getKey(Operator op)
{
	for(Key* key: this->keys)
	{
		if (dynamic_cast<KeyOperator*>(key) && ((KeyOperator*)key)-> getOperator() == op)
		{
			return key;
		}
	}
	throw new CalculatorError_PHG("Key with digit not found!");
};


Key* Keyboard_PHG::getKey(Control control)
{
	for(Key* key: this->keys)
	{
		if (dynamic_cast<KeyControl*>(key) && ((KeyControl*)key)-> getControl() == control)
		{
			return key;
		}
	}
	throw new CalculatorError_PHG("Key with digit not found!");
};


Key* Keyboard_PHG::getKey(Symbol symbol)
{
	for(int i = 0; i < this-> keys_qtt; i++)
	{
		if( this-> keys[i]-> getSymbol() == symbol ) return this-> keys[i];
	}
	throw new CalculatorError_PHG("Key with symbol not found!");
};


Keyboard_PHG::Keyboard_PHG()
{
	
}


void Keyboard_PHG::setCpu(Cpu* cpu)
{
	this-> cpu = cpu;
};


void Keyboard_PHG::add(Key* key)
{
	key-> setKeyboard(this);
	this-> keys.push_back(key);
	this-> keys_qtt++;
};