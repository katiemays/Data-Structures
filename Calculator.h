// SPECIFICATION FILE		( Calculator.h )
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stack>
#include "LinkedList.h"

class Calculator {  		// declares a class data type		
   
   public:
	Calculator();
	~Calculator();
 	void ConvertToPostfix(string infix);
	void PrintList();
	int GetListLength( char x );
	void PushList( char x );
	void Evaluate ();
	bool ErrorCheck ( string infix);
   private:		
	stack<ItemType> stack1;
	stack<char> charstack;
	stack<float> stack2;
 	LinkedList postfix;
	//void ifOperand(string infix, int& index, float& operand);
	//void ifOperand(string infix, int& index, string& flint);
};

#endif
