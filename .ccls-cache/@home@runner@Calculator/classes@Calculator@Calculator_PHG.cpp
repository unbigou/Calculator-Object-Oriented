#include "./Calculator_PHG.hpp"


Calculator_PHG::~Calculator_PHG()
{
	delete this-> cpu;
	delete this-> keyboard;
	delete this-> display;
}


void Calculator_PHG::setCpu(Cpu* cpu)
{
	this-> cpu = cpu;
}


void Calculator_PHG::setDisplay(Display* display)
{
	this-> display = display;
}


void Calculator_PHG::setKeyboard(Keyboard* keyboard)
{
	this-> keyboard = keyboard;
}


Cpu* Calculator_PHG::getCpu()
{
	return this-> cpu;
}


Display* Calculator_PHG::getDisplay()
{
	return this-> display;
}

	
Keyboard* Calculator_PHG::getKeyboard()
{
	return this-> keyboard;
}
