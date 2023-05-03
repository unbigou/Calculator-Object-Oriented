#include "../header/Calculator_PHG.hpp"

/*
	
	  /$$$$$$          /$$                  /$$           /$$                      
	 /$$__  $$        | $$                 | $$          | $$                      
	| $$  \__/ /$$$$$$| $$ /$$$$$$$/$$   /$| $$ /$$$$$$ /$$$$$$   /$$$$$$  /$$$$$$ 
	| $$      |____  $| $$/$$_____| $$  | $| $$|____  $|_  $$_/  /$$__  $$/$$__  $$
	| $$       /$$$$$$| $| $$     | $$  | $| $$ /$$$$$$$ | $$   | $$  \ $| $$  \__/
	| $$    $$/$$__  $| $| $$     | $$  | $| $$/$$__  $$ | $$ /$| $$  | $| $$      
	|  $$$$$$|  $$$$$$| $|  $$$$$$|  $$$$$$| $|  $$$$$$$ |  $$$$|  $$$$$$| $$      
	 \______/ \_______|__/\_______/\______/|__/\_______/  \___/  \______/|__/      
	                                   
*/

void Calculator_PHG::setCPU(CPU* cpu)
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


CPU* Calculator_PHG::getCPU()
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
