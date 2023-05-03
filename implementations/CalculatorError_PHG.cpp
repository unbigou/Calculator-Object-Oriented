#include "../header/CalculatorError_PHG.hpp"

/*
	
	  /$$$$$$          /$$                   /$$$$$$$$                                    
	 /$$__  $$        | $$                  | $$_____/                                    
	| $$  \__/ /$$$$$$| $$ /$$$$$$$         | $$       /$$$$$$  /$$$$$$  /$$$$$$  /$$$$$$ 
	| $$      |____  $| $$/$$_____/         | $$$$$   /$$__  $$/$$__  $$/$$__  $$/$$__  $$
	| $$       /$$$$$$| $| $$               | $$__/  | $$  \__| $$  \__| $$  \ $| $$  \__/
	| $$    $$/$$__  $| $| $$               | $$     | $$     | $$     | $$  | $| $$      
	|  $$$$$$|  $$$$$$| $|  $$$$$$$/$$      | $$$$$$$| $$     | $$     |  $$$$$$| $$      
	 \______/ \_______|__/\_______|__/      |________|__/     |__/      \______/|__/      
	                                                                                      
*/

CalculatorError_PHG::CalculatorError_PHG(Symbol message)
{
	this-> message = message;
}

Symbol CalculatorError_PHG::getMessage()
{
	return this-> message;
}