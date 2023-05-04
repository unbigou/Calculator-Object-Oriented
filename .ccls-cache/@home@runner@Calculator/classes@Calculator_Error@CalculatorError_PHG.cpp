#include "./CalculatorError_PHG.hpp"

CalculatorError_PHG::CalculatorError_PHG(char const* message)
{
	this-> message = message;
}

Symbol CalculatorError_PHG::getMessage()
{
	return this-> message;
}