#pragma once

#include "../../interface/Calculator.hpp"
#include <vector>

class Keyboard_PHG: public Keyboard 
{
    private:    
        Cpu* cpu;
		std::vector<Key*> keys;
		int keys_qtt = 0;
    public:
		Keyboard_PHG();

        void setCpu(Cpu*);
		void add(Key*);

        void receive(Digit);
        void receive(Operator);
        void receive(Control);

        Key* getKey(Digit);
        Key* getKey(Operator);        
        Key* getKey(Control);
        Key* getKey(Symbol);
};