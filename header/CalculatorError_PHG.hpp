#pragma once

#include "../interface/Calculator.hpp"

class CalculatorError_PHG: public CalculatorError
{
    private:
        Symbol message;
    public:
        Symbol getMessage();
        CalculatorError_PHG(Symbol);
};
