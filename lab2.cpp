#include <stack>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	
	// Variables
	stack <char> st;
	string input, filtered;
	int j=0;

	cout << "Enter a phrase : ";
	getline (cin, input);

	// Uses algorithm library to convert @input to lowercase
	transform(input.begin(), input.end(), input.begin(),(int (*)(int))tolower);

	// O(n) - Filters input to use only alphanumeric characters
	for (int i=0; i < input.length(); i++)
	{
	    if (isalnum(input[i]) != 0)
	    {
		st.push(input[i]);		
		filtered.insert(j,1,input[i]);
		j++;
	    }
	}	
	
	// Checking cleaned stack @st against cleaned string @filtered
	for (int i=0; i < filtered.length(); i++)
	{
	    if (st.top() != filtered[i])
	    {
		cout << "Phrase entered is NOT a palindrome." << endl;
		return 0;
	    }
	    if (!st.empty())	// to ensure we are not popping on an empty stack
		st.pop();
	}	
	
	cout << "Phrase is a palindrome!" << endl;
	return 0;
}
