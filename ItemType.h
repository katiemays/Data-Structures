//  SPECIFICATION FILE ItemType.h 
#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
using namespace std;
const int  MAX_ITEM = 5;
enum  RelationType { LESS, EQUAL, GREATER };

class  ItemType		// declares class data type
{
  friend ostream &operator<<(ostream &output, const ItemType& it )
  {  
     output<<it.value; 
     return output;
  }
						
/* 
  friend ostream &operator<<(ostream &output, const ItemType& it )
  {  
     if (it.symbol == '0')
        output<<it.operand;
     else if (it.operand == 0)
	output<<it.symbol;
     else
	output<<"empty node"; 
     return output;
  }
*/
public : 			

  ItemType() {}

  RelationType PriorityTo( ItemType otherItem ) const
  {   
    //incoming . priorityto (top of the stack) is higher...
    //if (value == '+' || value == '-' || value == '*' || value == '/') 
    //the thing on the stack has higher priority
    if (otherItem.value == '-' || otherItem.value == '+') {
	//...and the operand you are trying to push has low priority     
 	if (value == '*' || value == '/')
	   return GREATER;
	else
	   return LESS;
    }
    else
	return LESS;

  }
  RelationType ComparedTo( ItemType  otherItem ) const 
  {						
    if ( value  <  otherItem.value )
       return  LESS;
    else if ( value  > otherItem.value )
       return  GREATER;
    else  return  EQUAL;
  }

/*
  // compares symbols
  RelationType ComparedTo( ItemType  otherItem ) const 
  {						
    if ( symbol  <  otherItem.symbol )
       return  LESS;
    else if ( symbol  > otherItem.symbol )
       return  GREATER;
    else  return  EQUAL;
  }

  // compares symbol priority
  RelationType Priority( ItemType otherItem) const
  {
     if ( symbol == '+' || symbol == '-') {
	if (otherItem.symbol == '/' || otherItem.symbol == '*')
		return LESS;
        else
		return EQUAL;
     }
     else { //if symbol == * or / now:
	if (otherItem.symbol == '+' || otherItem.symbol == '-')
		return GREATER;
	else
		return EQUAL;
     }
  }
  ItemType operator = (const ItemType& it) 
  {
     symbol = it.symbol;
     operand = it.operand;
     return *this;
  }
*/
  void Print( ) const 
  {
   cout  <<  value  <<  endl;
  }

   void Initialize( int value )
  {
    this->value  =  value;              
  } 

/*
  // prints a symbol if item is a symbol, or prints operand if its a number
  void Print( ) const 
  {
    if (symbol != '0')   
       cout  <<  symbol  <<  endl;
    else 
       cout  << operand  <<  endl;
  }

  void InitializeSymbol( char symbol )
  {
    this->operand =  0;
    this->symbol  =  symbol;              
  } 	           

  void InitializeOperand ( float operand )
  {
    this->symbol   =  '0';
    this->operand  =  operand;
  }
*/
   char Reveal()
  {
	return value;
  }
	
private :
	char value;			// 1 private data member
//	char symbol; 		// could be any type 
//	float operand;
} ;
#endif	
