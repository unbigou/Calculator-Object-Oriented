#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include "./CPU_PHG.hpp"

Digit numbers[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};


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
}


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
};


CPU_PHG::CPU_PHG()
{
	for(int i = 0; i < 8; i++)
	{
		this-> log_1[i] = ZERO;
		this-> log_2[i] = ZERO;
		this-> memory[i] = ZERO;
	}
	this-> signal_log1 = POSITIVE;
	this-> signal_log2 = POSITIVE;
	this-> signal_memory = POSITIVE;

	this-> quantity_log1 = 0;
	this-> quantity_log2 = 0;
	this-> quantity_memory = 0;

	this-> decimal_separator_log1 = 0;
	this-> decimal_separator_log2 = 0;
	this-> decimal_separator_memory = 0;

	this-> operation = SUM;
	this-> control = EQUAL;
};


CPU_PHG::~CPU_PHG()
{	
	for(int i = 0; i < 8; i++)
	{
		this-> log_1[i] = ZERO;
		this-> log_2[i] = ZERO;
		this-> memory[i] = ZERO;
	}
	this-> signal_log1 = POSITIVE;
	this-> signal_log2 = POSITIVE;
	this-> signal_memory = POSITIVE;

	this-> quantity_log1 = ZERO;
	this-> quantity_log2 = ZERO;
	this-> quantity_memory = ZERO;

	this-> decimal_separator_log1 = ZERO;
	this-> decimal_separator_log2 = ZERO;
	this-> decimal_separator_memory = ZERO;

	free(this-> display);
};


void CPU_PHG::setDisplay(Display* display)
{
	this-> display = display;
};


void CPU_PHG::receive(Digit digit)
{
	if(this-> quantity_log1 < 8)
	{
		this-> log_1[this-> quantity_log1] = digit;
		this-> quantity_log1++;
	}
	else if(this-> quantity_log2 < 8)
	{
		this-> log_2[this-> quantity_log2] = digit;
		this-> quantity_log2++;
	}
};


void CPU_PHG::receive(Operator op)
{
	if(this-> quantity_log1 < 8)
	{
		for(int i = this-> quantity_log1; i < 8; i++)
		{
			this-> log_1[i] = ZERO;
		}
		quantity_log1 = 8;
	}
	this-> operation = op;
};


void CPU_PHG::receive(Control ctrl)
{
	switch(ctrl)
	{
		case ON_CLEAR_ERROR:
			for(int i = 0; i < 8; i++)
			{
				this-> log_1[i] = ZERO;
				this-> log_2[i] = ZERO;
			}
			this-> signal_log1 = POSITIVE;
			this-> signal_log2 = POSITIVE;
			this-> quantity_log1 = 0;
			this-> quantity_log2 = 0;
			this-> decimal_separator_log1 = 0;
			this-> decimal_separator_log2 = 0;
			break;
		
		case DECIMAL_SEPARATOR:
			if(this-> quantity_log2 > 0)
			{
				this-> decimal_separator_log2 = this-> quantity_log2;
			}
			else
			{
				this-> decimal_separator_log1 = this-> quantity_log1;
			}
			break;
		
		case EQUAL:
		{
			if(this-> quantity_log2 < 8)
			{
				for(int i = this-> quantity_log2; i < 8; i++) this-> receive(ZERO);
			}
			
			float log1 = toFloat(this-> log_1, this-> quantity_log1, this-> decimal_separator_log1, this-> signal_log1);
			float log2 = toFloat(this-> log_2, this-> quantity_log2, this-> decimal_separator_log2, this-> signal_log2);

			for(int i = 0 ; i < this-> quantity_log1; i++)
			{
				this-> display-> add(log_1[i]);
				if(i == this-> decimal_separator_log1 || this-> decimal_separator_log1 == 0)
				{
					this-> display-> addDecimalSeparator();
				}
			}
			
			switch(this-> operation)
			{
				case SUM:
					log1 += log2;
					std::cout << " + ";
					break;
				
				case SUBTRACTION:
					log1 -= log2;
					std::cout << " - ";
					break;
				
				case DIVISION:
					log1 /= log2;
					std::cout << " / ";
					break;
				
				case MULTIPLICATION:
					log1 *= log2;
					std::cout << " x ";
					break;
				
				case SQUARE_ROOT:
					if(this-> quantity_log2 > 0)
					{
						log2 = sqrt(log1);
						log1 = log2;
					}
					else log1 = sqrt(log1);
					break;
		
				case PERCENTAGE:
					if(this-> quantity_log1 < 8)
					{
						log1 = 0;
					}
					else
					{
						log1 /= (log2 /= 100);
					}
					break;		
			}
			
			for(int i = 0; i < this-> quantity_log2; i++)
			{
				this-> display-> add(log_2[i]);
				if(i == this-> decimal_separator_log1)
				{
					this-> display-> addDecimalSeparator();
				}
			}
			
			Digit* new_log = toDigit(log1, &this-> quantity_log1, &this-> decimal_separator_log1, &this-> signal_log1);
			for(int i = 0; i < 7; i++)
			{
				this-> log_1[i] = new_log[i];
			}
			
			// In any situation, EQUAL will print the result
			std::cout << " = ";
			for(int i = this-> quantity_log1-1; i >= 0; i--)
			{
				if(i == this-> decimal_separator_log1)
				{
					this-> display-> addDecimalSeparator();
				}
				this-> display-> add(log_1[i]);
			}
			break;
		}
		
		case MEMORY_SUBTRACTION:
			if(this-> quantity_log2 > 0)
			{
				float log2 = toFloat(this-> log_2, this-> quantity_log2, this-> decimal_separator_log2, this-> signal_log2);
				float mem = toFloat(this-> memory, this-> quantity_memory, this-> decimal_separator_memory, this-> signal_memory);
				mem -= log2;

				if(mem < 0)
				{
					this-> signal_memory = NEGATIVE;
				}
				else
				{
					this-> signal_memory = POSITIVE;
				}
				for(int i = 0; i < this-> quantity_memory; i++)
				{
					this-> memory[i] = ZERO;
				}
				this-> quantity_memory = 0;
			}
			break;
		
		case MEMORY_SUM:
			if(this-> quantity_log2 > 0)
			{
				float log2 = toFloat(this-> log_2, this-> quantity_log2, this-> decimal_separator_log2, this-> signal_log2);
				float mem = toFloat(this-> memory, this-> quantity_memory, this-> decimal_separator_memory, this-> signal_memory);
				mem += log2;

				int mem_quantity;
				int mem_separator;
				Signal mem_signal;
				Digit* new_mem = toDigit(mem, &mem_quantity, &mem_separator, &mem_signal);
				// Cleaning the memory for its new value
				for(int i = 0; i < this-> quantity_memory; i++)
				{
					this-> memory[i] = ZERO;
				}
				// Changing to the new values
				for(int i = 0; i < mem_quantity; i++)
				{
					this-> memory[i] = new_mem[i];
				}
				this-> signal_memory = mem_signal;
				this-> quantity_memory = mem_quantity;
				this-> decimal_separator_memory = mem_separator;


			}
			break;
		
		case MEMORY_READ_CLEAR:
			// Checking if its the first time MRC was been clicked
			if(this-> control != MEMORY_READ_CLEAR)
			{
				for(int i = 0; i < this-> quantity_memory; i++)
				{
					this-> memory[i] = ZERO;	
				}
				if(this-> quantity_log2 > 0)
				{
					for(int i = 0; i < this-> quantity_log2; i++)
					{
						this-> memory[i] = this-> log_2[i];
					}
					this-> signal_memory = this-> signal_log2;
					this-> quantity_memory = this-> quantity_log2;
					this-> decimal_separator_memory = this-> decimal_separator_log2;
				}
				else
				{
					for(int i = 0; i < this-> quantity_log1; i++)
					{
						this-> memory[i] = this-> log_1[i];
					}
					this-> signal_memory = this-> signal_log1;
					this-> quantity_memory = this-> quantity_log1;
					this-> decimal_separator_memory = this-> decimal_separator_log1;
				}
			}
			else
			{
				for(int i = 0; i < this-> quantity_memory; i++)
				{
					this-> memory[i] = ZERO;	
				}
				this-> quantity_memory = 0;
				this-> signal_memory = POSITIVE;
				this-> decimal_separator_memory = 0;
			}
			break;
		
		case OFF:
			break;
	}
	this-> control = ctrl;
};