#include "../../interface/Calculator.hpp"
#include "./support.hpp"

int firstNum(int value)
{
	if(value >= 10)
	{
		value /= 10;
		return firstNum(value);
	}
	return value;
}

bool nextDigit(Digit* digit)
{
	if(*digit != NINE)
	{
		*digit = numbers[*digit + 1];
		return false;
	}
	*digit = ZERO;
	return true;
}

void addOne(Digit** digit, int size)
{
	if(nextDigit(digit[size--]))
	{
		addOne(digit, size--);
	}
}

float toFloat(Digit* value, int quantity, int separator, Signal signal)
{
	float converted = 0;
	
	for(int i = quantity - 1; i >= 0; i--)
	{
		converted += value[i] * pow(10, i);
	}
	converted /= pow(10, separator);
	if(signal == NEGATIVE)
	{
		converted = -converted;
	}
	return converted;
};

Digit* toDigit(float value, int* quantity, int* separator, Signal* signal)
{
	// Making sure that all values are empty
	*quantity = 0; *separator = 0; *signal = POSITIVE;
	Digit* converted = (Digit*) malloc(sizeof(Digit) * 8);
	for(int i = 0; i < 8; i++)
	{
		converted[i] = ZERO;	
	}
	// Saving the signal them turning it positive if needed
	if(value < 0)
	{
		value *= 1; 
		*signal = NEGATIVE;
	}

	int value_i = (int) value;
	float value_f = value - value_i;
	// Converting the integer part of the number
	while((*quantity) < 8)
	{
		if(value_i != 0)
		{
			converted[*quantity] = numbers[firstNum(value_i)];
			(*quantity)++;
			(*separator)++;
		}
		else break;
		
		value_i /= 10;
	}
	// Converting the float part of the number
	int aux = value;
	while(*quantity < 8)
	{
		if(value - aux > 0)
		{
			value_f *= 10;
			converted[*quantity] = numbers[(int) value_f];
			*quantity++;
			// Fixing the float accurancy
			if(*quantity == 8)
			{
				if(value_f * 10 > 0)
				{
					addOne(&converted, 8);
				}
			}
		}
		else break;
	}
	return converted;
}