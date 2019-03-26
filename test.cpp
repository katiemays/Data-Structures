#include "Calculator.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

   // Variables
   string infix;
   Calculator eq;

   cout << "Enter your equation here, or 'exit': ";
   getline(cin, infix);

   eq.ConvertToPostfix(infix);
   cout << endl;

   eq.PushList('p');

   eq.Evaluate();   
   return 0;
}
