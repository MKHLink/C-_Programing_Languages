//Linkhon Hasan
//6/8/2024

#include <iostream>
#include "Account.h"
#include "Util.h"

using namespace std;

int main() {
	string userInput;
	Account account;

	//do while loop that initializes the GUI in terminal
	do {
		getUserInput(account);
		showUserInput(account);
		cout << endl;
		cout << endl;
		showUserWithNoPayment(account);
		cout << endl;
		cout << endl;
		showUserWithMonthlyPayment(account);
		cout << endl;

		cout << "Press any button to enter different values" << endl;
		cout << "Press n to exit program!" << endl;
		cin >> userInput;
	} while (userInput != "n");
	
	return 1;
}