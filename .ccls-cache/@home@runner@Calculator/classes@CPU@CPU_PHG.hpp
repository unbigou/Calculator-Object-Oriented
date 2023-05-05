#pragma once

#include <vector>
#include "../../interface/Calculator.hpp"

using namespace std;

class CPU_PHG: public Cpu
{
    private:
		Display* display;
        Operator operation;
		Control control;

		bool monitor;
		Control last_control;

        vector<Digit> log_1;
        vector<Digit> log_2;
        vector<Digit> memory;

        Signal signal_log1;
        Signal signal_log2;
        Signal signal_memory;

    public:
        CPU_PHG();
        ~CPU_PHG();

		void setDisplay(Display*);
		void receive(Digit);
		void receive(Operator);
		void receive(Control);
};