#include "../header/CalculatorError_PHG.hpp"


CalculatorError_PHG::CalculatorError_PHG(Symbol message)
{
	this-> message = message;
}

Symbol CalculatorError_PHG::getMessage()
{
	return this-> message;
}