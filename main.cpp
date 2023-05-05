#include "./interface/Calculator.hpp"
#include "./classes/Calculator/Calculator_PHG.hpp"
#include "./classes/Calculator_Error/CalculatorError_PHG.hpp"
#include "./classes/CPU/CPU_PHG.hpp"
#include "./classes/Display/Display_PHG.hpp"
#include "./classes/Keyboard/Keyboard_PHG.hpp"
#include "./classes/Keyboard/KeyControl/KeyControl.hpp"
#include "./classes/Keyboard/KeyDigit/KeyDigit.hpp"
#include "./classes/Keyboard/KeyOperator/KeyOperator.hpp"

Calculator* buildCalculator() 
{
	Calculator *calculator = new Calculator_PHG();
	Display *display = new Display_PHG();
	Cpu *cpu = new CPU_PHG();
	Keyboard *keyboard = new Keyboard_PHG();
	
	KeyDigit *keyZero = new KeyDigit_PHG("0", ZERO);
	KeyDigit *keyOne = new KeyDigit_PHG("1", ONE);
	KeyDigit *keyTwo = new KeyDigit_PHG("2", TWO);
	KeyDigit *keyThree = new KeyDigit_PHG("3", THREE);
	KeyDigit *keyFour = new KeyDigit_PHG("4", FOUR);
	KeyDigit *keyFive = new KeyDigit_PHG("5", FIVE);
	KeyDigit *keySix = new KeyDigit_PHG("6", SIX);
	KeyDigit *keySeven = new KeyDigit_PHG("7", SEVEN);
	KeyDigit *keyEight = new KeyDigit_PHG("8", EIGHT);
	KeyDigit *keyNine = new KeyDigit_PHG("9", NINE);
	
	KeyOperator *keySum = new KeyOperator_PHG("+", SUM);
	KeyOperator *keySubtraction = new KeyOperator_PHG("-", SUBTRACTION);
	KeyOperator *keyMultiplication = new KeyOperator_PHG("*", MULTIPLICATION);
	KeyOperator *keyDivision = new KeyOperator_PHG("/", DIVISION);
	KeyOperator *keySquareRoot = new KeyOperator_PHG("Sqrt", SQUARE_ROOT);
	KeyOperator *keyPercentage = new KeyOperator_PHG("%", PERCENTAGE);
	
	KeyControl *keyEqual = new KeyControl_PHG("=", EQUAL);
	KeyControl *keyClearError = new KeyControl_PHG("ON_CE", ON_CLEAR_ERROR);
	KeyControl *keyOff = new KeyControl_PHG("OFF", OFF);
	KeyControl *keyMemoryReadClear = new KeyControl_PHG("MRC", MEMORY_READ_CLEAR);
	KeyControl *keyMemorySum = new KeyControl_PHG("M+", MEMORY_SUM);
	KeyControl *keyMemorySubtraction = new KeyControl_PHG("M-", MEMORY_SUBTRACTION);
	
	keyboard->add(keyZero);
	keyboard->add(keyOne);
	keyboard->add(keyTwo);
	keyboard->add(keyThree);
	keyboard->add(keyFour);
	keyboard->add(keyFive);
	keyboard->add(keySix);
	keyboard->add(keySeven);
	keyboard->add(keyEight);
	keyboard->add(keyNine);
	
	keyboard->add(keySum);
	keyboard->add(keySubtraction);
	keyboard->add(keyMultiplication);
	keyboard->add(keyDivision);
	keyboard->add(keySquareRoot);
	
	keyboard->add(keyEqual);
	keyboard->add(keyClearError);
	keyboard->add(keyOff);
	keyboard->add(keyMemoryReadClear);
	keyboard->add(keyMemorySum);
	keyboard->add(keyMemorySubtraction);
	
	keyboard->setCpu(cpu);
	cpu->setDisplay(display);
	
	calculator->setDisplay(display);
	calculator->setCpu(cpu);
	calculator->setKeyboard(keyboard);
	
	return calculator;
}

int main()
{
	
	return 0;
}
