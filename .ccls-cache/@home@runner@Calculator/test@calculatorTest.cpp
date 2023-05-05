#include "calculatorTest.hpp"
#include <functional>
#include <iostream>


/** Implementação das classes de teste
---------------------------------------------*/
TestCalculatorBase::TestCalculatorBase(Calculator *calculator) {
  this->calculator = calculator;
}
void TestCalculatorBase::setup() {
  std::cout << "Iniciando teste..." << this->getName() << std::endl;
  calculator->getKeyboard()->getKey(ON_CLEAR_ERROR)->press();
}
void TestCalculatorBase::tearDown() {
  calculator->getKeyboard()->getKey(OFF)->press();
  std::cout << "\nTeste finalizado..." << std::endl;
}

/**
  123 + 456 = = = = 1947
*/
TestCalculator1::TestCalculator1(Calculator *calculator)
    : TestCalculatorBase(calculator) {}
void TestCalculator1::setup() {
  this->TestCalculatorBase::setup();
  calculator->getKeyboard()->getKey("0")->press();
}

void TestCalculator1::run() {
  Symbol test[] = {"1", "2", "3", "+", "4", "5", "6", "=", "=", "=", "="};
  for (Symbol s : test)
    calculator->getKeyboard()->getKey(s)->press();
}
char const *TestCalculator1::getName() {
  return " Testando 123 + 456 = = = = 1947";
}

/**
  .1 * .1 = 0.01
*/
TestCalculator2::TestCalculator2(Calculator *calculator)
    : TestCalculatorBase(calculator) {}

void TestCalculator2::run() {
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(MULTIPLICATION)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
}

char const *TestCalculator2::getName() {
  return " Testando 123 + 456 = = = = 1947";
}

TestCalculatorSmart::TestCalculatorSmart(Calculator *, Symbol tests[], int testsCount): TestCalculatorBase(calculator) {
  this->tests.push_back(tests);
}

void TestCalculatorSmart::run()
{
  Symbol test[11] = {"1", "2", "3", "+", "4", "5", "6", "="};
  for (Symbol s : test)
    calculator->getKeyboard()->getKey(s)->press();
}
char const *TestCalculatorSmart::getName() {
  return " Testando 123 + 456 = = = = 1947";
}

/** Implementação das funções de teste
---------------------------------------------*/
/**
  123 + 456 = = = = 1947
*/
void test1(Calculator *calculator) {
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(TWO)->press();
  calculator->getKeyboard()->getKey(THREE)->press();
  calculator->getKeyboard()->getKey(SUM)->press();
  calculator->getKeyboard()->getKey(FOUR)->press();
  calculator->getKeyboard()->getKey(FIVE)->press();
  calculator->getKeyboard()->getKey(SIX)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
}

/**
  .1 * .1 = 0.01
*/
void test2(Calculator *calculator) {
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(SUM)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
}
/**
  .1 * .1 = 0.01
*/
void test3(Calculator *calculator) {
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(SUM)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
}
/**
  .1 * .1 = 0.01
*/
void test4(Calculator *calculator) {
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(SUM)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
}



Calculator *buildCalculator() {
	/* Build da calculadora */
	
	Calculator *calculator = new Calculator_PHG();
	Display *display = new Display_PHG();
	Cpu *cpu = new CPU_PHG();
	Keyboard *keyboard = new Keyboard_PHG();
	
	/* ... Criar todas as teclas */
	KeyDigit* keyZero = new KeyDigit_PHG("0", ZERO);
	KeyDigit* keyOne = new KeyDigit_PHG("1", ONE);
	KeyDigit* keyTwo = new KeyDigit_PHG("2", TWO);
	KeyDigit* keyThree = new KeyDigit_PHG("3", THREE);
	KeyDigit* keyFour = new KeyDigit_PHG("4", FOUR);
	KeyDigit* keyFive = new KeyDigit_PHG("5", FIVE);
	KeyDigit* keySix = new KeyDigit_PHG("6", SIX);
	KeyDigit* keySeven = new KeyDigit_PHG("7", SEVEN);
	KeyDigit* keyEight = new KeyDigit_PHG("8", EIGHT);
	KeyDigit* keyNine = new KeyDigit_PHG("9", NINE);
	
	KeyOperator* keySum = new KeyOperator_PHG("+", SUM);
	KeyOperator* keySubtraction = new KeyOperator_PHG("-", SUBTRACTION);
	KeyOperator* keyMultiplication = new KeyOperator_PHG("*", MULTIPLICATION);
	KeyOperator* keyDivision = new KeyOperator_PHG("/", DIVISION);
	KeyOperator* keySqrt = new KeyOperator_PHG("SQRT", SQUARE_ROOT);
	KeyOperator* keyPercentage = new KeyOperator_PHG("%", PERCENTAGE);
	
	KeyControl* keyEqual = new KeyControl_PHG("=", EQUAL);
	KeyControl* keyClearError = new KeyControl_PHG("ON_CE", ON_CLEAR_ERROR);
	KeyControl* keyOff = new KeyControl_PHG("OFF", OFF);
	KeyControl* keyMemoryReadClear =new KeyControl_PHG("MRC", MEMORY_READ_CLEAR);
	KeyControl* keyMemorySum = new KeyControl_PHG("M+", MEMORY_SUM);
	KeyControl* keyMemorySubtraction = new KeyControl_PHG("M-", MEMORY_SUBTRACTION);
	
	/* ... Inserir todas as teclas no teclado  */
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
	
	keyboard->add(keyEqual);
	keyboard->add(keyClearError);
	keyboard->add(keyOff);
	keyboard->add(keyMemoryReadClear);
	keyboard->add(keyMemorySum);
	keyboard->add(keyMemorySubtraction);
	
	keyboard->setCpu(cpu);
	
	cpu->setDisplay(display);
	
	/* Conectando as partes da calculadora */
	
	calculator->setDisplay(display);
	calculator->setCpu(cpu);
	calculator->setKeyboard(keyboard);
	
	return calculator;
}

void mainTest() {

  try {
    std::cout << "Construindo a calculadora..." << std::endl;
    Calculator *calculator = buildCalculator();
    /** Execução dos testes Orientados a Objetos
    ---------------------------------------------*/

    std::vector<Test *> calculatorTests;
    calculatorTests.push_back(new TestCalculator1(calculator));
    calculatorTests.push_back(new TestCalculator2(calculator));

    for (Test *test : calculatorTests) {
      try {
        test->setup();
        test->run();
        test->tearDown();
      } catch (CalculatorError &e) {
        std::cout << "Algum erro aconteceu: " << e.getMessage();
      }
    }

    /** Execução dos testes estruturados
    ---------------------------------------------*/
    std::cout << "\nIniciando teste1..." << std::endl;
    calculator->getKeyboard()->getKey(ON_CLEAR_ERROR)->press();
    test1(calculator);
    std::cout << "\nIniciando teste2..." << std::endl;
    calculator->getKeyboard()->getKey(ON_CLEAR_ERROR)->press();
    test2(calculator);
    std::cout << "\nIniciando teste3..." << std::endl;
    calculator->getKeyboard()->getKey(ON_CLEAR_ERROR)->press();
    test3(calculator);
    std::cout << "\nIniciando teste4..." << std::endl;
    calculator->getKeyboard()->getKey(ON_CLEAR_ERROR)->press();
    test4(calculator);

    /** Execução dos testes estruturados mais organizados
    ---------------------------------------------*/
    std::function<void(Calculator *)> calculatorTests_[] = {&test1, &test2,
                                                            &test3, &test4};
    try {
      int i = 0;
      for (std::function<void(Calculator *)> test : calculatorTests_) {
        std::cout << "Iniciando teste..." << i++ << std::endl;
        calculator->getKeyboard()->getKey(ON_CLEAR_ERROR)->press();
        test(calculator);
      }
    } catch (CalculatorError &e) {
      std::cout << "Algum erro aconteceu: " << e.getMessage();
    }

    delete calculator;
  } catch (CalculatorError *error) {
    std::cout << "Tests failed: " << error->getMessage();
  }
}