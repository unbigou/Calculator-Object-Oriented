#pragma once

#include <iostream>
#include <vector>
#include "../interface/Calculator.hpp"

/** Definição de testes orientados a objetos 
---------------------------------------------*/
class Test
{
	public:
		virtual void setup() = 0;
		virtual void run() = 0;
		virtual void tearDown() = 0;
};


class TestCalculatorBase: public Test
{
	protected:
		Calculator* calculator;
	public:
		TestCalculatorBase(Calculator*);
		void setup();
		void tearDown();
		
		virtual Symbol getName() = 0;
};


class TestCalculator1: public TestCalculatorBase
{
	public:
		TestCalculator1(Calculator*);
		void setup();
		void run();
		Symbol getName();
};


class TestCalculator2: public TestCalculatorBase
{
	public:
		TestCalculator2(Calculator*);
		void run();
		Symbol getName();
};


/** Definição de testes estruturados 
---------------------------------------------*/
Calculator* buildCalculator();

void test1(Calculator*);
void test2(Calculator*);

void mainTest();
