#pragma once

#include "./interface/Calculator.hpp"
#include <stdint.h>

typedef char* const Symbol;

class Display_PHG: public Display
{
    private:
        Signal signal;
    public:
        void add(Digit);
        void setSignal(Signal);
        void addDecimalSeparator();
        void clear();
};


class CPU_PHG: public CPU
{
    private:
        Digit numbers[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
		Display* display;
        Operator operation;

        Digit log_1[8];
        Digit log_2[8];
        Digit memory[8];
        Signal signal_log1;
        Signal signal_log2;
        Signal signal_memory;

        uint32_t quantity_log1;
        uint32_t quantity_log2;
        uint32_t quantity_memory;
        uint32_t decimal_separator_log1;    
        uint32_t decimal_separator_log2;
        uint32_t decimal_separator_memory;

        // Support functions
        int firstNum(uint32_t);

    public:
        CPU_PHG();
        ~CPU_PHG();

		void setDisplay(Display*);
		void setLog(Digit);
		void setOperation(Operator);
		void setControl(Control);
        float toFloat(Digit*, uint32_t, uint32_t, Signal);
        Digit* toDigit(float, uint32_t*, uint32_t*, Signal*);
};

#include <vector>
class Keyboard_PHG: public Keyboard 
{
    private:    
        CPU* cpu;
		std::vector<Key*> keys;
		int keys_qtt = 0;
    public:
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


class KeyDigit_PHG: public KeyDigit 
{
	private:
		Keyboard* keyboard;
		Symbol symbol;
		Digit digit;
    public:
		void setKeyboard(Keyboard*);
		void press();
		KeyDigit_PHG(Symbol, Digit);
        Digit get();
		Symbol getSymbol();
};


class KeyOperator_PHG: public KeyOperator
{	private:
		Keyboard* keyboard;
		Symbol symbol;
		Operator op;
    public:
		void setKeyboard(Keyboard*);
		void press();
		KeyOperator_PHG(Symbol, Operator);
        Operator get();
		Symbol getSymbol();
};


class KeyControl_PHG: public KeyControl
{
	private:
		Keyboard* keyboard;
		Symbol symbol;
		Control ctrl;
    public:
		void setKeyboard(Keyboard*);
		void press();
		KeyControl_PHG(Symbol, Control);
        Control get();
		Symbol getSymbol();
};


class Calculator_PHG: public Calculator
{
    private:
        CPU* cpu;
        Display* display;
        Keyboard* keyboard;
    public:
        void setCPU(CPU*);
        void setDisplay(Display*);
        void setKeyboard(Keyboard*);
        CPU* getCPU();
        Display* getDisplay();
        Keyboard* getKeyboard();
};


class CalculatorError_PHG: public CalculatorError
{
    private:
        Symbol message;
    public:
        Symbol getMessage();
        CalculatorError_PHG(Symbol);
};
