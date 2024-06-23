//Linkhon Hasan
//5/24/2024

#include "Clock.h"
#include <iostream>

using namespace std;

//function to print line of stars
void printStars() {
	for (int i = 0; i < 27; i++) {
		cout << "*";
	}
}

//function to display the clock, takes clock object as argument
void displayClocks(const Clock& showClock) {
	printStars();
	cout << "     ";
	printStars();
	cout << endl;
	cout << "*      12-Hour Clock:     *";
	cout << "     ";
	cout << "*      24-Hour Clock:     *" << endl;
	cout << "*      ";
	showClock.get12HourFormat();
	cout << "       *";
	cout << "     ";
	cout << "*      ";
	showClock.get24HourFormat();
	cout << "           *"<<endl;
	printStars();
	cout << "     ";
	printStars();
	cout << endl;
}

//displays menu to the user
void showMenu() {
	printStars();
	cout << endl;
	cout<<"* 1. Add One Hour         *\n";
	cout<<"* 2. Add One Minute       *\n";
	cout<<"* 3. Add One Second       *\n";
	cout<<"* 4. Exit                 *\n";
	printStars();
	cout << endl;
}

//main driver
int main() {

	Clock clock;
	clock.setTime();
	int choice;


	//starts the loop and keeps going unless the user picks 4
	do {
		displayClocks(clock);
		cout << endl;
		showMenu();

		cin >> choice;

		//discards anything other than 1,2,3 or 4,clears any error flag
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			cout << "Invalid input. Please press 1, 2, 3, or 4." << endl;
			cout << endl;
			continue;
		}

		//switch case for user choices
		switch (choice) {
		case 1:
			clock.addHours();
			break;
		case 2:
			clock.addMinutes();
			break;
		case 3:
			clock.addSecond();
			break;
		case 4:
			break;
		default:
			cout << "Please press 1,2,3 or 4.";
		}
	} while (choice != 4);


	return 0;
}