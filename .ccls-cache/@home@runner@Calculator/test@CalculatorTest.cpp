#include "CalculatorTest.hpp"
#include <functional>
#include <iostream>
#include <vector>

/** Implementação das classes de teste
---------------------------------------------*/
TestCalculatorBase::TestCalculatorBase(Calculator *calculator) 
{
	this->calculator = calculator;
}


void TestCalculatorBase::setup() 
{
	std::cout << "TEST STARTED\n" << this->getName() << std::endl;
	calculator-> getKeyboard()-> get(ON_CLEAR_ERROR)-> press();
}


void TestCalculatorBase::tearDown() 
{
	calculator-> getKeyboard()-> get(OFF)-> press();
	std::cout << "TEST ENDED" << std::endl;
}


TestCalculator1::TestCalculator1(Calculator *calculator) : TestCalculatorBase(calculator) 
{
	
}


void TestCalculator1::setup() 
{
	printf("Test Calculator1 -");
	this-> TestCalculatorBase::setup();
	this-> calculator-> getKeyboard()-> get("0")-> press();
	printf("* Test Calculator");
}


void TestCalculator1::run() 
{
	Symbol test[] = {"1", "2", "3", "+", "4", "5", "6", "=", "=", "=", "="};
	for(Symbol s : test)
	{
		calculator-> getKeyboard()-> get(s)-> press();
	}
}


char const *TestCalculator1::getName() 
{
	return " Test: 123 + 456 = = = = 1947";
}


TestCalculator2::TestCalculator2(Calculator* calculator) : TestCalculatorBase(calculator) 
{
	
}


void TestCalculator2::run() 
{
	calculator-> getKeyboard()-> get(DECIMAL_SEPARATOR)-> press();
	calculator-> getKeyboard()-> get(ONE)-> press();
	calculator-> getKeyboard()-> get(SUM)-> press();
	calculator-> getKeyboard()-> get(DECIMAL_SEPARATOR)-> press();
	calculator-> getKeyboard()-> get(ONE)-> press();
	calculator-> getKeyboard()-> get(EQUAL)-> press();
}


const char* TestCalculator2::getName() 
{
	return " ,1 + ,1 =";
}


TestCalculatorSmart::TestCalculatorSmart(Calculator* calculator, Symbol tests[], int testsCount) : TestCalculatorBase(calculator) 
{
	this-> tests = tests;
}


void TestCalculatorSmart::run() 
{
	Symbol test[] = {"1", "2", "3", "+", "4", "5", "6", "=", "=", "=", "="};
	for(Symbol s : test)
	{
		calculator-> getKeyboard()-> get(s)-> press();	
	}
}


char const *TestCalculatorSmart::getName() {
  return " Testando 123 + 456 = = = = 1947\n";
}


void test1(Calculator* calculator) 
{
	calculator-> getKeyboard()-> get(ONE)-> 	press();
	printf("one ");
	calculator-> getKeyboard()-> get(TWO)-> 	press();
	printf("two ");
	calculator-> getKeyboard()-> get(THREE)-> 	press();
	printf("three ");
	calculator-> getKeyboard()-> get(SUM)-> 	press();
	printf("+ ");
	calculator-> getKeyboard()-> get(FOUR)-> 	press();
	printf("four ");
	calculator-> getKeyboard()-> get(FIVE)-> 	press();
	printf("five ");
	calculator-> getKeyboard()-> get(SIX)-> 	press();
	printf("six ");
	calculator-> getKeyboard()-> get(EQUAL)-> 	press();
	printf("= ");
	calculator-> getKeyboard()-> get(EQUAL)-> 	press();
	printf("= ");
	calculator-> getKeyboard()-> get(EQUAL)-> 	press();
	printf("= ");
	calculator-> getKeyboard()-> get(EQUAL)-> 	press();
	printf("= ");
}


void test2(Calculator* calculator) 
{	
	calculator-> getKeyboard()-> get(DECIMAL_SEPARATOR)-> 	press();
	calculator-> getKeyboard()-> get(ONE)->               	press();
	calculator-> getKeyboard()-> get(SUM)->               	press();
	calculator-> getKeyboard()-> get(DECIMAL_SEPARATOR)-> 	press();
	calculator-> getKeyboard()-> get(ONE)->               	press();
	calculator-> getKeyboard()-> get(EQUAL)->             	press();
}


void test3(Calculator* calculator) 
{
	calculator-> getKeyboard()-> get(DECIMAL_SEPARATOR)->	press();
	calculator-> getKeyboard()-> get(ONE)->					press();
	calculator-> getKeyboard()-> get(SUM)->					press();
	calculator-> getKeyboard()-> get(DECIMAL_SEPARATOR)->	press();
	calculator-> getKeyboard()-> get(ONE)->					press();
	calculator-> getKeyboard()-> get(EQUAL)->				press();
}


void test4(Calculator* calculator) 
{
	calculator-> getKeyboard()-> get(DECIMAL_SEPARATOR)->	press();
	calculator-> getKeyboard()-> get(ONE)->					press();
	calculator-> getKeyboard()-> get(SUM)->					press();
	calculator-> getKeyboard()-> get(DECIMAL_SEPARATOR)->	press();
	calculator-> getKeyboard()-> get(ONE)->					press();
	calculator-> getKeyboard()-> get(EQUAL)->				press();
}


#include "../header/Calculator_PHG.hpp"
#include "../header/CalculatorError_PHG.hpp"
#include "../header/CPU_PHG.hpp"
#include "../header/Display_PHG.hpp"
#include "../header/Keyboard_PHG.hpp"

Calculator* buildCalculator() 
{
  /* Build da calculadora */
  Calculator* calculator = new Calculator_PHG();
  Display* display = new Display_PHG();
  CPU* cpu = new CPU_PHG();
  Keyboard* keyboard = new Keyboard_PHG();

  /* ... Criar todas as teclas */
  KeyDigit *keyZero 	= new KeyDigit_PHG("0", ZERO);
  KeyDigit *keyOne		= new KeyDigit_PHG("1", ONE);
  KeyDigit *keyTwo 		= new KeyDigit_PHG("2", TWO);
  KeyDigit *keyThree 	= new KeyDigit_PHG("3", THREE);
  KeyDigit *keyFour 	= new KeyDigit_PHG("4", FOUR);
  KeyDigit *keyFive 	= new KeyDigit_PHG("5", FIVE);
  KeyDigit *keySix 		= new KeyDigit_PHG("6", SIX);
  KeyDigit *keySeven	= new KeyDigit_PHG("7", SEVEN);
  KeyDigit *keyEight	= new KeyDigit_PHG("8", EIGHT);
  KeyDigit *keyNine 	= new KeyDigit_PHG("9", NINE);

  KeyOperator *keySum 				= new KeyOperator_PHG("+", SUM);
  KeyOperator *keySubtraction 		= new KeyOperator_PHG("-", SUBTRACTION);
  KeyOperator *keyMultiplication 	= new KeyOperator_PHG("*", MULTIPLICATION);
  KeyOperator *keyDivision 			= new KeyOperator_PHG("/", DIVISION);
  KeyOperator *keySquareRoot 		= new KeyOperator_PHG("SQRT", SQUARE_ROOT);
  KeyOperator *keyPercentage 		= new KeyOperator_PHG("%", PERCENTAGE);

  KeyControl *keyEqual 				= new KeyControl_PHG("=", EQUAL);
  KeyControl *keyDecimalSeparator 	= new KeyControl_PHG(".", DECIMAL_SEPARATOR);
  KeyControl *keyClearError 		= new KeyControl_PHG("ON_CE", ON_CLEAR_ERROR);
  KeyControl *keyOff 				= new KeyControl_PHG("OFF", OFF);
  KeyControl *keyMemoryReadClear 	= new KeyControl_PHG("MRC", MEMORY_READ_CLEAR);
  KeyControl *keyMemorySum 			= new KeyControl_PHG("M+", MEMORY_SUM);
  KeyControl *keyMemorySubtraction 	= new KeyControl_PHG("M-", MEMORY_SUBTRACTION);

  /* ... Inserir todas as teclas no teclado  */
  keyboard-> add(keyZero);
  keyboard-> add(keyOne);
  keyboard-> add(keyTwo);
  keyboard-> add(keyThree);
  keyboard-> add(keyFour);
  keyboard-> add(keyFive);
  keyboard-> add(keySix);
  keyboard-> add(keySeven);
  keyboard-> add(keyEight);
  keyboard-> add(keyNine);

  keyboard-> add(keySum);
  keyboard-> add(keySubtraction);
  keyboard-> add(keyMultiplication);
  keyboard-> add(keyDivision);
  keyboard-> add(keySquareRoot);
  keyboard-> add(keyPercentage);

  keyboard-> add(keyEqual);
  keyboard-> add(keyClearError);
  keyboard-> add(keyDecimalSeparator);
  keyboard-> add(keyOff);
  keyboard-> add(keyMemoryReadClear);
  keyboard-> add(keyMemorySum);
  keyboard-> add(keyMemorySubtraction);

  keyboard-> setCPU(cpu);

  cpu-> setDisplay(display);

  /* Conectando as partes da calculadora */
  calculator-> setDisplay(display);
  calculator-> setCPU(cpu);
  calculator-> setKeyboard(keyboard);

  return calculator;
}


void mainTest() 
{
	try 
	{
		std::cout << "Building calculator..." << std::endl;
		Calculator* calculator = buildCalculator();
		
		std::vector<Test *> calculatorTests;
		calculatorTests.push_back(new TestCalculator1(calculator));
		calculatorTests.push_back(new TestCalculator2(calculator));
		
		for (Test *test : calculatorTests) 
		{
	  		try 
			{
				test-> setup();
				test-> run();
				test-> tearDown();
		  	} 
			catch (CalculatorError &e) 
			{
				std::cout << "ERROR: " << e.getMessage();
			}
		}

		std::cout << "Inicializing teste1..." << std::endl;
		calculator-> getKeyboard()-> get(ON_CLEAR_ERROR)-> press();
		test1(calculator);
		
		std::cout << "Inicializing teste2..." << std::endl;
		calculator-> getKeyboard()-> get(ON_CLEAR_ERROR)-> press();
		test2(calculator);
		
		std::cout << "Inicializing teste3..." << std::endl;
		calculator-> getKeyboard()-> get(ON_CLEAR_ERROR)-> press();
		test3(calculator);
		
		std::cout << "Inicializing teste4..." << std::endl;
		calculator-> getKeyboard()-> get(ON_CLEAR_ERROR)-> press();
		test4(calculator);

		std::function<void(Calculator *)> calculatorTests_[] = { &test1, &test2, &test3, &test4 };
		try 
		{
		  	int i = 0;
		  	for (std::function<void(Calculator *)> test : calculatorTests_) 
			{
				std::cout << "Inicializing teste..." << i++ << std::endl;
				calculator-> getKeyboard()-> get(ON_CLEAR_ERROR)-> press();
				test(calculator);
			}
		} 
		catch (CalculatorError &e) 
		{
			std::cout << "ERROR: " << e.getMessage();
		}
		
		delete calculator;
	} 
		
	catch (CalculatorError *error) 
	{
		std::cout << "Tests failed: " << error->getMessage();
	}
}