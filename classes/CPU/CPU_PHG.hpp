#pragma once

#include "../../interface/Calculator.hpp"

class CPU_PHG: public CPU
{
    private:
		Display* display;
        Operator operation;
		Control control;

        Digit log_1[8];
        Digit log_2[8];
        Digit memory[8];
        Signal signal_log1;
        Signal signal_log2;
        Signal signal_memory;

        int quantity_log1;
        int quantity_log2;
        int quantity_memory;
        int decimal_separator_log1;    
        int decimal_separator_log2;
        int decimal_separator_memory;

    public:
        CPU_PHG();
        ~CPU_PHG();

		void setDisplay(Display*);
		void receive(Digit);
		void receive(Operator);
		void receive(Control);
};