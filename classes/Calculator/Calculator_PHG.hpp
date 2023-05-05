#pragma once

#include "../../interface/Calculator.hpp"

class Calculator_PHG: public Calculator
{
    private:
        Cpu* cpu;
        Display* display;
        Keyboard* keyboard;
    public:
		~Calculator_PHG();

        void setCpu(Cpu*);
        void setDisplay(Display*);
        void setKeyboard(Keyboard*);

        Cpu* getCpu();
        Display* getDisplay();
        Keyboard* getKeyboard();
};
