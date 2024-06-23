/*
 * Calculator.cpp
 *
 *  Date: 5/19/2024
 *  Author: Linkhon Hasan
 */

#include <iostream>

using namespace std;

void main()
{
	int op1, op2;
	char operation;
	//answer was initialized as a string, changed it to a char by placing it within a '' and also ; was missing to end statement
	char answer = 'Y';
	//changed 'y' to capital 'Y' so while condition would match
	//changed operation from op1/op2, op1-op2 to op2/op1, op2-op1 for better accuracy based on input
		while (answer == 'Y')
		{
			cout << "Enter expression" << endl;
			cin >> op2 >> operation >> op1;
			//"+" is a string, which can not be compared to a char, so changed it to '+' to make it a char
			//removed ; from line 27 to ensure proper if statement
			if (operation == '+')
			//>> after op2 should be << operator
			cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
			//removed ; from line 31 to ensure proper if statement
			if (operation == '-')
			//>> after cout should be << operator
			cout << op2 << " - " << op1 << " = " << op2 - op1 << endl;
			if (operation == '*')
				//like 36 was missing a ; to end statement and changed print out symbol to match the operation
				cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;
			if (operation == '/')
				//changed output symbol to match operation
				
					cout << op2 << " / " << op1 << " = " << op2 / op1 << endl;

			cout << "Do you wish to evaluate another expression? " << endl;
			cin >> answer;
		}
		cout<<"Program Finished" <<endl;
}






