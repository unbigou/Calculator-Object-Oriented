#pragma once

#include "../interface/Calculator.hpp"
#include <vector>


class Keyboard_PHG: public Keyboard 
{
    private:    
        CPU* cpu;
		std::vector<Key*> keys;
		int keys_qtt = 0;
    public:
		Keyboard_PHG();

        void setCPU(CPU*);
		void add(Key*);
        void read(Digit);
        void read(Operator);
        void read(Control);
        Key* get(Digit);
        Key* get(Operator);        
        Key* get(Control);
        Key* get(Symbol);
};


class KeyControl_PHG: public KeyControl
{
	private:
		Keyboard* keyboard;
		Symbol symbol;
		Control control;
    public:
		KeyControl_PHG(Symbol, Control);

		void setKeyboard(Keyboard*);
		void press();
        Control get();
		Symbol getSymbol();
};


class KeyDigit_PHG: public KeyDigit 
{
	private:
		Keyboard* keyboard;
		Symbol symbol;
		Digit digit;
    public:
		KeyDigit_PHG(Symbol, Digit);

		void setKeyboard(Keyboard*);
		void press();
        Digit get();
		Symbol getSymbol();
};


class KeyOperator_PHG: public KeyOperator
{	private:
		Keyboard* keyboard;
		Symbol symbol;
		Operator op;
    public:
		KeyOperator_PHG(Symbol, Operator);

		void setKeyboard(Keyboard*);
		void press();
        Operator get();
		Symbol getSymbol();
};