#include <iostream>

#include "../header/Keyboard_PHG.hpp"
#include "../header/CalculatorError_PHG.hpp"

/*

	 /$$   /$$                  /$$                                       /$$
	| $$  /$$/                 | $$                                      | $$
	| $$ /$$/  /$$$$$$ /$$   /$| $$$$$$$  /$$$$$$  /$$$$$$  /$$$$$$  /$$$$$$$
	| $$$$$/  /$$__  $| $$  | $| $$__  $$/$$__  $$|____  $$/$$__  $$/$$__  $$
	| $$  $$ | $$$$$$$| $$  | $| $$  \ $| $$  \ $$ /$$$$$$| $$  \__| $$  | $$
	| $$\  $$| $$_____| $$  | $| $$  | $| $$  | $$/$$__  $| $$     | $$  | $$
	| $$ \  $|  $$$$$$|  $$$$$$| $$$$$$$|  $$$$$$|  $$$$$$| $$     |  $$$$$$$
	|__/  \__/\_______/\____  $|_______/ \______/ \_______|__/      \_______/
	                   /$$  | $$                                             
	                  |  $$$$$$/                                             
	                   \______/       
					
*/
void Keyboard_PHG::read(Digit digit)
{
	if(this-> cpu)
	{
    	this-> cpu-> setLog(digit);
	}
	else
	{
    	std::cerr << "Keyboard without cpu!\n";
	}
};


void Keyboard_PHG::read(Operator op)
{
	if(this-> cpu)
	{
    	this-> cpu-> setOperator(op);
	}
	else
	{
    	std::cerr << "Keyboard without cpu!\n";
	}
};


void Keyboard_PHG::read(Control control)
{
	if(this-> cpu)
	{
    	this-> cpu-> setControl(control);
	}
	else
	{
    	std::cerr << "Keyboard without cpu!\n";
	}
};


Key* Keyboard_PHG::get(Digit digit)
{
	for (Key *key : this->keys)
	{
		if (dynamic_cast<KeyDigit*>(key) && ((KeyDigit*)key)-> get() == digit)
		{
			return key;
		}
	}
	throw new CalculatorError_PHG("Key with digit not found!");
};


Key* Keyboard_PHG::get(Operator op)
{
	for (Key *key : this->keys)
	{
		if (dynamic_cast<KeyOperator*>(key) && ((KeyOperator*)key)-> get() == op)
		{
			return key;
		}
	}
	throw new CalculatorError_PHG("Key with digit not found!");
};


Key* Keyboard_PHG::get(Control control)
{
	for (Key *key : this->keys)
	{
		if (dynamic_cast<KeyControl*>(key) && ((KeyControl*)key)-> get() == control)
		{
			return key;
		}
	}
	throw new CalculatorError_PHG("Key with digit not found!");
};


Key* Keyboard_PHG::get(Symbol symbol)
{
	for(Key* key : this->keys)
	{
		if( key-> getSymbol() == symbol ) return key;
	}
	throw new CalculatorError_PHG("Key with symbol not found!");
};


Keyboard_PHG::Keyboard_PHG()
{
	
}


void Keyboard_PHG::setCPU(CPU* cpu)
{
	this-> cpu = cpu;
};


void Keyboard_PHG::add(Key* key)
{
	if (key != NULL) 
	{
	    this-> keys.push_back(key);
	    key-> setKeyboard(this);
  	}
};

/*
	 /$$                              /$$/$$         /$$  /$$    
	| $$                             | $|__/        |__/ | $$    
	| $$   /$$ /$$$$$$ /$$   /$$ /$$$$$$$/$$ /$$$$$$ /$$/$$$$$$  
	| $$  /$$//$$__  $| $$  | $$/$$__  $| $$/$$__  $| $|_  $$_/  
	| $$$$$$/| $$$$$$$| $$  | $| $$  | $| $| $$  \ $| $$ | $$    
	| $$_  $$| $$_____| $$  | $| $$  | $| $| $$  | $| $$ | $$ /$$
	| $$ \  $|  $$$$$$|  $$$$$$|  $$$$$$| $|  $$$$$$| $$ |  $$$$/
	|__/  \__/\_______/\____  $$\_______|__/\____  $|__/  \___/  
	                   /$$  | $$            /$$  \ $$            
	                  |  $$$$$$/           |  $$$$$$/            
	                   \______/             \______/             
*/
KeyDigit_PHG::KeyDigit_PHG(Symbol symbol, Digit digit)
{
	this-> symbol = symbol;
	this-> digit = digit;
}


void KeyDigit_PHG::setKeyboard(Keyboard* keyboard)
{
	this-> keyboard = keyboard;
}


void KeyDigit_PHG::press()
{
	if (this-> keyboard != NULL)
	{
		this-> keyboard-> read(this-> digit);
	}
}


Digit KeyDigit_PHG::get()
{
	return this-> digit;
}


Symbol KeyDigit_PHG::getSymbol()
{
	return this-> symbol;
}

/*
	 /$$                                                     /$$                      /$$
	| $$                                                    | $$                     | $$
	| $$   /$$ /$$$$$$ /$$   /$$ /$$$$$$$ /$$$$$$ /$$$$$$$ /$$$$$$   /$$$$$$  /$$$$$$| $$
	| $$  /$$//$$__  $| $$  | $$/$$_____//$$__  $| $$__  $|_  $$_/  /$$__  $$/$$__  $| $$
	| $$$$$$/| $$$$$$$| $$  | $| $$     | $$  \ $| $$  \ $$ | $$   | $$  \__| $$  \ $| $$
	| $$_  $$| $$_____| $$  | $| $$     | $$  | $| $$  | $$ | $$ /$| $$     | $$  | $| $$
	| $$ \  $|  $$$$$$|  $$$$$$|  $$$$$$|  $$$$$$| $$  | $$ |  $$$$| $$     |  $$$$$$| $$
	|__/  \__/\_______/\____  $$\_______/\______/|__/  |__/  \___/ |__/      \______/|__/
	                   /$$  | $$                                                         
	                  |  $$$$$$/                                                         
	                   \______/                                                          
*/
KeyControl_PHG::KeyControl_PHG(Symbol symbol, Control control)
{
	this-> symbol = symbol;
	this-> control = control;
}


void KeyControl_PHG::setKeyboard(Keyboard* keyboard)
{
	this-> keyboard = keyboard;
}

void KeyControl_PHG::press()
{
	if (this-> keyboard != NULL)
	{
		this-> keyboard-> read(this-> control);
	}
}


Control KeyControl_PHG::get()
{
	return this-> control;
}


Symbol KeyControl_PHG::getSymbol()
{
	return this-> symbol;
}

/*
	 /$$                                                                      /$$                      
	| $$                                                                     | $$                      
	| $$   /$$ /$$$$$$ /$$   /$$ /$$$$$$  /$$$$$$  /$$$$$$  /$$$$$$ /$$$$$$ /$$$$$$   /$$$$$$  /$$$$$$ 
	| $$  /$$//$$__  $| $$  | $$/$$__  $$/$$__  $$/$$__  $$/$$__  $|____  $|_  $$_/  /$$__  $$/$$__  $$
	| $$$$$$/| $$$$$$$| $$  | $| $$  \ $| $$  \ $| $$$$$$$| $$  \__//$$$$$$$ | $$   | $$  \ $| $$  \__/
	| $$_  $$| $$_____| $$  | $| $$  | $| $$  | $| $$_____| $$     /$$__  $$ | $$ /$| $$  | $| $$      
	| $$ \  $|  $$$$$$|  $$$$$$|  $$$$$$| $$$$$$$|  $$$$$$| $$    |  $$$$$$$ |  $$$$|  $$$$$$| $$      
	|__/  \__/\_______/\____  $$\______/| $$____/ \_______|__/     \_______/  \___/  \______/|__/      
	                   /$$  | $$        | $$                                                           
	                  |  $$$$$$/        | $$                                                           
	                   \______/         |__/                                                           
*/
KeyOperator_PHG::KeyOperator_PHG(Symbol symbol, Operator op)
{
	this-> symbol = symbol;
	this-> op = op;
}


void KeyOperator_PHG::setKeyboard(Keyboard* keyboard)
{
	this-> keyboard = keyboard;
}


void KeyOperator_PHG::press()
{
	if (this-> keyboard != NULL)
	{
		this-> keyboard-> read(this-> op);
	}
}


Operator KeyOperator_PHG::get()
{
	return this-> op;
}


Symbol KeyOperator_PHG::getSymbol()
{
	return this-> symbol;
}