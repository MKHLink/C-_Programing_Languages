#include "Util.h"
#include <iostream>
#include <iomanip>

using namespace std; 

//allows to user to input values for their account by using setters
void getUserInput(Account& t_account) {
    double amount;
    double deposit;
    double interest;
    int years;

    cout << "*********************************" << endl;
    cout << "********* Data Input ************" << endl;

    //all the cin to get user input for setters are encased in do while logic to validate user input
    //this ensures real positive values for data allocation
    do {
        cout << "Initial Investment Amount: ";
        cin >> amount;
        if (amount <= 0 || cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input." << endl;
        }
    } while (amount <= 0 || cin.fail());
    t_account.setInitialAmount(amount);

    do {
        cout << "Monthly Deposit: ";
        cin >> deposit;
        if (deposit < 0 || cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input." << endl;
        }
    } while (deposit < 0 || cin.fail());
    t_account.setMonthlyAmount(deposit);

    do {
        cout << "Annual Interest: ";
        cin >> interest;
        if (interest <= 0 || cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input." << endl;
        }
    } while (interest <= 0 || cin.fail());
    t_account.setInterest(interest);

    do {
        cout << "Number of years: ";
        cin >> years;
        if (years <= 0 || cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input." << endl;
        }
    } while (years <= 0 || cin.fail());
    t_account.setYears(years);
}


//shows the user input values for visibility
void showUserInput(const Account& t_account) {
    cout << "*********************************" << endl;
    cout << "********* Data Input ************" << endl;
    cout << "Initial Investment Amount: " << t_account.getInitialAmount() << endl;
    cout << "Monthly Deposit " << t_account.getMonthlyAmount() << endl;
    cout << "Annual Interest: " << t_account.getInterest() << endl;
    cout << "Number of years: " << t_account.getYears() << endl;
}

//displays the terminal with no monlthy payments from user
void showUserWithNoPayment(const Account& t_account) {
    double balance = t_account.getInitialAmount();
    cout << "    Balance and Interest Without Additional Monthly Deposits    " << endl;
    cout << "==================================================================" << endl;
    cout << "Year         Year End Balance             Year End Earned interest" << endl;
    //first loop iterates over the number of years
    for (int i = 0; i < t_account.getYears(); i++) {
        double yearEndInterest = 0;
        //second loop iterates over every 12 months in a year and adds it to the balance
        for (int k = 1; k <= 12; k++) {
            yearEndInterest += yearlyInterest(balance, 0, t_account.getInterest());
            //only the interest is added as not monthly payment is being made
            balance += yearlyInterest(balance, 0, t_account.getInterest());
        }
        cout << i + 1 << "              " << fixed << setprecision(2) << balance << "                 "   << yearEndInterest<<endl;
    }
}

//displays the terminal with monthly payments from user
void showUserWithMonthlyPayment(const Account& t_account) {
    double balance = t_account.getInitialAmount();
    cout << "    Balance and Interest Without Additional Monthly Deposits    " << endl;
    cout << "==================================================================" << endl;
    cout << "Year         Year End Balance             Year End Earned interest" << endl;
    //first loop iterates over the number of years
    for (int i = 0; i < t_account.getYears(); i++) {
        double yearEndInterest = 0;
        //second loop iterates over every 12 months in a year and adds it to the balance
        for (int k = 1; k <= 12; k++) {
            yearEndInterest += yearlyInterest(balance, t_account.getMonthlyAmount(), t_account.getInterest());
            //the monthly amount is added along with the monthly interest to the yearly balance
            balance += (t_account.getMonthlyAmount() + yearlyInterest(balance, t_account.getMonthlyAmount(), t_account.getInterest()));
        }
        cout << i + 1 << "              " << fixed << setprecision(2)<< balance << "                 "  << yearEndInterest <<endl;
    }
}

//calculates the monthly interest
double yearlyInterest(double t_initBalance, double t_monthlyAmount,double t_interestRate) {
    return ((t_initBalance+t_monthlyAmount)*((t_interestRate / 100) /12));
}

