#pragma once

#include <iostream>
#include <vector>
#include "../interface/Calculator.hpp"
#include "../classes/Calculator/Calculator_PHG.hpp"
#include "../classes/Calculator_Error/CalculatorError_PHG.hpp"
#include "../classes/CPU/CPU_PHG.hpp"
#include "../classes/Display/Display_PHG.hpp"
#include "../classes/Keyboard/Keyboard_PHG.hpp"
#include "../classes/Keyboard/KeyControl/KeyControl.hpp"
#include "../classes/Keyboard/KeyDigit/KeyDigit.hpp"
#include "../classes/Keyboard/KeyOperator/KeyOperator.hpp"

/** Definição de testes orientados a objetos 
---------------------------------------------*/
class Test{
  public:
    virtual void setup() = 0;
    virtual void run() = 0;
    virtual void tearDown() = 0;
};

class TestCalculatorBase: public Test{
  protected:
    Calculator* calculator;
  public:
    TestCalculatorBase(Calculator*);
    void setup();
    void tearDown();

    virtual char const * getName() = 0;
};


class TestCalculator1: public TestCalculatorBase{
  public:
    TestCalculator1(Calculator*);
    void setup();
    void run();
    char const * getName();
};

class TestCalculator2: public TestCalculatorBase{
  public:
    TestCalculator2(Calculator*);
    void run();
    char const * getName();
};

class TestCalculatorSmart: public TestCalculatorBase{
    std::vector<Symbol*> tests;
  public:
    TestCalculatorSmart(Calculator*, Symbol tests[], int testsCount);
    void run();
    char const * getName();
};


/** Definição de testes estruturados 
---------------------------------------------*/
Calculator* buildCalculator();
void test1(Calculator*);
void test2(Calculator*);
void test3(Calculator*);
void test4(Calculator*);

void mainTest();