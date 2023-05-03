#pragma once

#include "../interface/Calculator.hpp"

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
