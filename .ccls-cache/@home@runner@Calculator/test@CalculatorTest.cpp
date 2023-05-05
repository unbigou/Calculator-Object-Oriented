// #include "CalculatorTest.hpp"
// #include <functional>
// #include <iostream>
// #include <vector>

// #include "../classes/CPU/CPU_PHG.hpp"
// #include "../classes/Display/Display_PHG.hpp"
// #include "../classes/Keyboard/Keyboard_PHG.hpp"
// #include "../classes/Keyboard/KeyOperator/KeyOperator.hpp"
// #include "../classes/Keyboard/KeyDigit/KeyDigit.hpp"
// #include "../classes/Keyboard/KeyControl/KeyControl.hpp"
// #include "../classes/Calculator/Calculator_PHG.hpp"
// #include "../classes/Calculator_Error/CalculatorError_PHG.hpp"

/** Implementação das classes de teste
---------------------------------------------*/
TestCalculatorBase::TestCalculatorBase(Calculator *calculator) 
{
	this->calculator = calculator;
}


void TestCalculatorBase::setup() 
{
	std::cout << "TEST STARTED\n" << this->getName() << std::endl;
	calculator-> getKeyboard()-> getKey(ON_CLEAR_ERROR)-> press();
}


void TestCalculatorBase::tearDown() 
{
	calculator-> getKeyboard()-> getKey(OFF)-> press();
	std::cout << "\nTEST ENDED" << std::endl;
}


TestCalculator1::TestCalculator1(Calculator *calculator) : TestCalculatorBase(calculator) 
{
	
}


void TestCalculator1::setup() 
{
	
}


void TestCalculator1::run() 
{
	Symbol test[] = {"1", "2", "+", "2", "3", "="};
	for(Symbol s : test)
	{
		calculator-> getKeyboard()-> getKey(s)-> press();
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
	calculator-> getKeyboard()-> getKey(ONE)->				 press();
	calculator-> getKeyboard()-> getKey(SUM)->				 press();
	calculator-> getKeyboard()-> getKey(ONE)->				 press();
	calculator-> getKeyboard()-> getKey(EQUAL)->			 press();
}


const char* TestCalculator2::getName() 
{
	return "1 + 1 =";
}


void test1(Calculator* calculator) 
{
	calculator-> getKeyboard()-> getKey(ONE)-> 		press();
	calculator-> getKeyboard()-> getKey(TWO)-> 		press();
	calculator-> getKeyboard()-> getKey(THREE)-> 	press();
	calculator-> getKeyboard()-> getKey(SUM)-> 		press();
	calculator-> getKeyboard()-> getKey(FOUR)-> 	press();
	calculator-> getKeyboard()-> getKey(FIVE)-> 	press();
	calculator-> getKeyboard()-> getKey(SIX)-> 		press();
	calculator-> getKeyboard()-> getKey(EQUAL)-> 	press();
}


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
		
		std::vector<Test*> calculatorTests;
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
		
		delete calculator;
	} 
		
	catch (CalculatorError *error) 
	{
		std::cout << "Tests failed: " << error->getMessage();
	}
}