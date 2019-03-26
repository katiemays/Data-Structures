#include "Calculator.h"
#include <sstream>
#include <string>
#include <stdlib.h>

Calculator::Calculator() {
  //initialize things here
  //nothing to be initialized here ... 
}
Calculator::~Calculator() {
  //nothing needs to be deleted or freed here
}
// currently only works for SINGLE DIGIT INTs
void Calculator::ConvertToPostfix(string infix) {

   string flint; // float integer
   float operand;
   string temp; 
   ItemType item;
   ItemType op;
   op.Initialize('(');
   bool notDone;

   for (int i=0; i<infix.length(); i++) {
	item.Initialize(infix[i]);
	notDone = true;

	if (infix[i] >= '0' && infix[i] <= '9') {
	   //ifOperand(infix, i, flint);
	   //item.InitializeOperand(operand); 
	   postfix.InsertItem(item);
	   cout << item;
	   cout << " ";
	}
	else if (infix[i] == '(') { 
	   //item.InitializeSymbol(infix[i]);
	   stack1.push(item);
	}
	else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*') {
	   do {
	      if (stack1.empty() || (stack1.top()).ComparedTo(op) == EQUAL  || item.PriorityTo(stack1.top()) == GREATER) {
		   //item.InitializeSymbol(infix[i]);
		   stack1.push(item);
		   notDone = false;
	      }
	      else {
		   postfix.InsertItem(stack1.top());
		   cout << stack1.top();
		   cout << " ";
	    	   stack1.pop();
	      }
	   } while (notDone);
	}	
	else if (infix[i] == ')') {
	   while ((stack1.top()).ComparedTo(op) != EQUAL) {
		postfix.InsertItem(stack1.top());
		cout << stack1.top();
		cout << " ";
		stack1.pop();
	   }
	   if ((stack1.top()).ComparedTo(op) == EQUAL)
		stack1.pop();
	}
   }
   
   while (!stack1.empty()) {
	postfix.InsertItem(stack1.top());
	cout << stack1.top();
	cout << " ";
	stack1.pop();
   }
   cout <<endl;
}
/*
 * dealing if multiple digit inputs , attempt to convert to float
void Calculator::ifOperand(string infix, int& index, string& flint)
//void Calculator::ifOperand(string infix, int& index, float& operand)
{
   string tempchar;

   while (infix[index] == ' ' || infix[index] >= 0 && infix[index] <= 9)
   {
     if (infix[index] != ' ') {
	tempchar = infix[index];
	flint.append(tempchar);
     }
     index++; // when index is incremented here, it also increments in the function it was called in
   } 
   index--; // take it back one because in the for loop it was called in, it will be incremented once
   //stringstream ss(flint); 
   //ss >> operand;
}*/

void Calculator::PrintList() 
{
   int length;
   ItemType item;

   postfix.ResetList();
   length = postfix.GetLength();

   for (int counter= 1; counter <= length; counter++)
   {
	postfix.GetNextItem(item);
	item.Print();
   }
}

int Calculator::GetListLength(char x)
{
   if (x == 'p')
     	return postfix.GetLength();
   else
	return -1;
}
// because linked list adds to the front, i pushed the linked list into a stack
// i know this is not an efficient solution, but it worked for the time being and problem at hand!
void Calculator::PushList( char x)
{
   ItemType item;
   if (x == 'p') {
	postfix.ResetList();
	for (int i=0; i<postfix.GetLength(); i++) {
 	    postfix.GetNextItem(item);
	    charstack.push(item.Reveal());
	}
   }
   else
	cout << "no list found" << endl;
}
//algorithm 2
//evaluates postfix expression that has been pushed onto a stack to retain correct order 
void Calculator::Evaluate()
{
   float num, num1, num2;
   char top;
   while (!charstack.empty()) {
	top = charstack.top();
	if (top >= '0' && top <= '9') {
	    num = top - '0';
	    stack2.push(num);
	}
	else {
	    //get operand2
	    num2 = stack2.top();
	    stack2.pop();
	    
	    //get operand1
	    num1 = stack2.top();
	    stack2.pop();

	    switch(top) {
		case '+':
		  num = num1 + num2;
		  stack2.push(num);
		  break;
		case '-':
		  num = num1 - num2;
		  stack2.push(num);
		  break;
		case '*':
		  num = num1 * num2;
		  stack2.push(num);
		  break;
		case '/':
		  num = num1 / num2;
		  stack2.push(num);
		  break;
	    }
	}
	charstack.pop();
   }
 
   cout << "  ->   " << stack2.top() << endl;
   stack2.pop();
}
bool Calculator::ErrorCheck( string infix )
{
   stack <char> temp;

   for (int i = 0; i < infix.length(); i++) {
      if (infix[i] == '/' && infix[i+1] == '0') {
	cout << "Cannot divide by zero, retry." << endl;
	return false;
      }
      else if (infix[i] == '(')
	temp.push(infix[i]);
      else if (infix[i] == ')') {
	while (!temp.empty() && temp.top() != '(')
	   temp.pop();
	if (temp.top() == '(')
	   temp.pop();
      }
   }
   if (!temp.empty()) {
     cout << "Check syntax and retry. " << endl;
     return false;
   }
   else
     return true;
}
