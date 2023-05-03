#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../header/Display_PHG.hpp"
#include "../header/CalculatorError_PHG.hpp"

/*

	 /$$$$$$$ /$$                  /$$                  
	| $$__  $|__/                 | $$                  
	| $$  \ $$/$$ /$$$$$$$ /$$$$$$| $$ /$$$$$$ /$$   /$$
	| $$  | $| $$/$$_____//$$__  $| $$|____  $| $$  | $$
	| $$  | $| $|  $$$$$$| $$  \ $| $$ /$$$$$$| $$  | $$
	| $$  | $| $$\____  $| $$  | $| $$/$$__  $| $$  | $$
	| $$$$$$$| $$/$$$$$$$| $$$$$$$| $|  $$$$$$|  $$$$$$$
	|_______/|__|_______/| $$____/|__/\_______/\____  $$
	                     | $$                  /$$  | $$
	                     | $$                 |  $$$$$$/
	                     |__/                  \______/ 

*/
void Display_PHG::add(Digit digit)
{   
    switch(digit)
    {
        case ZERO :	std::cout << 0; break;
        case ONE  :	std::cout << 1; break;
        case TWO  :	std::cout << 2; break;
        case THREE: std::cout << 3; break;
        case FOUR :	std::cout << 4; break;
        case FIVE :	std::cout << 5; break;
        case SIX  :	std::cout << 6; break;
        case SEVEN: std::cout << 7; break;
        case EIGHT: std::cout << 8; break;
        case NINE :	std::cout << 9; break;
        default:
			std::cout << "E";
            throw new CalculatorError_PHG("Digit not implemented!"); break;
    }
};

void Display_PHG::setSignal(Signal signal)
{
    std::cout << (signal == NEGATIVE? "-":"");
};

void Display_PHG::addDecimalSeparator()
{
    std::cout << ".";
};

void Display_PHG::clear()
{  
    system("cls");
};