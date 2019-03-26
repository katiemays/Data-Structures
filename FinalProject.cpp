#include "Calculator.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

   // Variables
   string infix;
   int cont = 1;
   Calculator eq;

   system("clear");

   while (cont > 0) {
     if (infix == "exit") {
        cout << "Goodbye!" << endl;
 	return 0;
     }

   	cout << ",-------------------------------," << endl;
   	cout << "|                               |" << endl;
   	cout << "|   ,-----------------------,   |" << endl;
   	cout << "|   |                       |   |" << endl;
   
     if (cont == 1) {
   	cout << "|   |    Welcome to the     |   |" << endl;
   	cout << "|   |      Calculator!      |   |" << endl; 
     }
     else if (cont == 2) {
   	cout << "|   |   Infix -> Postfix    |   |" << endl; 
   	cout << "|   | ";
   	eq.ConvertToPostfix(infix);
     }
     else if (cont == 3) {
	eq.PushList('p');
   	cout << "|   |       *ANSWER*        |   |" << endl; 
   	cout << "|   | ";
	eq.Evaluate();
     }

	cout << "|   |                       |   |" << endl;
   	cout << "|   '-----------------------'   |" << endl;
   	cout << "|    ,---, ,---, ,---, ,---,    |" << endl;
   	cout << "|    | . | | ( | | ) | | / |    |" << endl;
   	cout << "|    '---' '---' '---' '---'    |" << endl;
   	cout << "|    ,---, ,---, ,---, ,---,    |" << endl;
   	cout << "|    | 7 | | 8 | | 9 | | * |    |" << endl;
   	cout << "|    '---' '---' '---' '---'    |" << endl;
   	cout << "|    ,---, ,---, ,---, ,---,    |" << endl;
   	cout << "|    | 4 | | 5 | | 6 | | - |    |" << endl;
   	cout << "|    '---' '---' '---' '---'    |" << endl;
   	cout << "|    ,---, ,---, ,---, ,---,    |" << endl;
   	cout << "|    | 1 | | 2 | | 3 | | + |    |" << endl;
   	cout << "|    '---' '---' '---' '---'    |" << endl;
   	cout << "|    ,---------, ,---------,    |" << endl;
   	cout << "|    |    0    | |    =    |    |" << endl;
   	cout << "|    '---------' '---------'    |" << endl;
   	cout << "|                               |" << endl;
   	cout << "'-------------------------------'" << endl;
   	cout << endl;
   
    if (cont == 3) {
	cout << "Would you like to enter another equation? ";
        getline(cin, infix);
    	
	if (infix == "Y" || infix == "YES" || infix == "Yes" || infix == "yes" || infix == "y")
	   cont = 1;
        else
	   infix = "exit";
    }
    else if (cont == 2) {
	cout << "Continue on to evaluate this? ";
	getline(cin, infix);

	if (infix == "Y" || infix == "YES" || infix == "Yes" || infix == "yes" || infix == "y")
	   cont++;
        else
	   infix = "exit";
    }
    else if (cont == 1) {
	cout << "1. This program only works with single digit numbers.\n";
	cout << "2. Watch your syntax!\n";
	cout << endl;
  	cout << "Enter your equation here, or 'exit': ";
   	getline(cin, infix);
    	if (!eq.ErrorCheck(infix))
	   cont++;
    }
     system("clear");
   }

   return 0;
}
