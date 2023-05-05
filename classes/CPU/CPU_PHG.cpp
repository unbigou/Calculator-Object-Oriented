#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <iostream>
#include <vector>
#include "./CPU_PHG.hpp"

using namespace std;

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


int toInt(vector<Digit> value, Signal signal)
{
	int converted = 0;
	int base = pow(10, value.size() - 1);

	for(int i = 0; i < value.size(); i++)
	{
		converted += (value[i] * base);
		base /= 10;
	}
	
	if(signal == NEGATIVE)
	{
		converted = -converted;
	}
	return converted;
}


vector<Digit> toDigit(int value, Signal* signal)
{
	*signal = POSITIVE;
	
	vector<Digit> converted;
	
	if(value < 0)
	{
		value = -value; 
		*signal = NEGATIVE;
	}

	int index = 0;
	while(value > 0)
	{
		converted.push_back(numbers[value % 10]);
		value /= 10;
		index++;
	}

	for(int i = 0, f = converted.size() - 1; i < f; i++, f--)
	{
		Digit aux = converted[i];
		converted[i] = converted[f];
		converted[f] = aux;
	}
	
	return converted;
}


CPU_PHG::CPU_PHG()
{
	this-> signal_log1 = POSITIVE;
	this-> signal_log2 = POSITIVE;
	this-> signal_memory = POSITIVE;
	
	this-> operation = SUM;
	this-> control = EQUAL;

	this-> monitor = true;
	this-> last_control = EQUAL;
};


CPU_PHG::~CPU_PHG()
{	
	this-> log_1.clear();
	this-> log_2.clear();
	this-> memory.clear();

	this-> signal_log1 = POSITIVE;
	this-> signal_log2 = POSITIVE;
	this-> signal_memory = POSITIVE;

	free(this-> display);
};


void CPU_PHG::setDisplay(Display* display)
{
	this-> display = display;
};


void CPU_PHG::receive(Digit digit)
{ 
	if(this-> monitor) this-> log_1.push_back(digit);
	else this-> log_2.push_back(digit);
};


void CPU_PHG::receive(Operator op)
{
	this-> operation = op;
	this-> monitor = false;
};


void CPU_PHG::receive(Control ctrl)
{
	switch(ctrl)
	{
		case ON_CLEAR_ERROR:
			this-> log_1.clear();
			this-> log_2.clear();
			
			this-> signal_log1 = POSITIVE;
			this-> signal_log2 = POSITIVE;
			
			break;
		
		case EQUAL:
		{
			int log1 = toInt(this-> log_1, this-> signal_log1);
			int log2 = toInt(this-> log_2, this-> signal_log2);

			switch(this-> operation)
			{
				case SUM:
					log1 += log2;
					break;
				
				case SUBTRACTION:
					log1 -= log2;
					break;
				
				case DIVISION:
					log1 /= log2;
					break;
				
				case MULTIPLICATION:
					log1 *= log2;
					break;
				
				case SQUARE_ROOT:
					if(this-> log_2.size() > 0)
					{
						log2 = sqrt(log1);
						log1 = log2;
					}
					else log1 = sqrt(log1);
					break;
		
				case PERCENTAGE:
					if(this-> log_1.size() < 8)
					{
						log1 = 0;
					}
					else
					{
						log1 /= (log2 /= 100);
					}
					break;		
			}
			vector<Digit> new_log = toDigit(log1, &this-> signal_log1);

			this-> log_1.clear();			
			for(Digit d: new_log) this-> log_1.push_back(d);

			this-> display-> setSignal(this-> signal_log1);
			for(Digit d: this-> log_1) this-> display-> add(d);
			
			break;
		}
		
		case MEMORY_SUBTRACTION:
			if(!monitor)
			{
				float log2 = toInt(this-> log_2, this-> signal_log2);
				float mem = toInt(this-> memory, this-> signal_memory);
				
				mem -= log2;

				if(mem < 0)
				{
					this-> signal_memory = NEGATIVE;
				}
				else
				{
					this-> signal_memory = POSITIVE;
				}
				vector<Digit> new_log = toDigit(mem, &this-> signal_memory);
	
				this-> memory.clear();			
				for(Digit d: new_log) this-> memory.push_back(d);
	
				this-> display-> setSignal(this-> signal_memory);
				for(Digit d: this-> memory) this-> display-> add(d);
			}
			break;
		
		case MEMORY_SUM:
			if(!monitor)
			{
				int log2 = toInt(this-> log_2, this-> signal_log2);
				int mem = toInt(this-> memory, this-> signal_memory);
				
				mem += log2;

				if(mem < 0)
				{
					this-> signal_memory = NEGATIVE;
				}
				else
				{
					this-> signal_memory = POSITIVE;
				}
				vector<Digit> new_log = toDigit(mem, &this-> signal_memory);
	
				this-> memory.clear();			
				for(Digit d: new_log) this-> memory.push_back(d);
	
				this-> display-> setSignal(this-> signal_memory);
				for(Digit d: this-> memory) this-> display-> add(d);
			}
			break;
		
		case MEMORY_READ_CLEAR:
			if(this-> last_control != MEMORY_READ_CLEAR)
			{
				int mem = 0;
				
				if(monitor) mem = toInt(this-> log_1, this-> signal_log1);
				else mem = toInt(this-> log_2, this-> signal_log2);

				if(mem < 0)
				{
					this-> signal_memory = NEGATIVE;
				}
				else
				{
					this-> signal_memory = POSITIVE;
				}
				
				vector<Digit> new_mem = toDigit(mem, &this-> signal_memory);
	
				this-> memory.clear();			
				for(Digit d: new_mem) this-> memory.push_back(d);
	
				this-> display-> setSignal(this-> signal_memory);
				for(Digit d: this-> memory) this-> display-> add(d);
			}
			else
			{
				this-> memory.clear();
				this-> signal_memory = POSITIVE;
			}
			break;
		
		case OFF:
			this-> ~CPU_PHG();
			break;
	}
	this-> last_control = ctrl;
};