#pragma once

#include "../interface/Calculator.hpp"

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
