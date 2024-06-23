#ifndef Util_H
#define Util_H
#include "Account.h"

//declaring utility functions 
void getUserInput(Account& t_account);
void showUserInput(const Account& t_account);
void showUserWithNoPayment(const Account& t_account);
void showUserWithMonthlyPayment(const Account& t_account);
double yearlyInterest(double t_initBalance, double t_monthlyAmount, double t_interestRate);

#endif // !Util_H