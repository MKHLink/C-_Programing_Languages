#include "Account.h"

//Defining all the memebr functions of Accounting.h
// No argument constructor, sets everything to 0
Account::Account() : m_initialAmount(0.0), m_monthlyDeposit(0.0), m_interest(0.0), m_years(0) {}

// All arg constructor
Account::Account(double t_initialAmount, double t_monthlyDeposit, double t_interest, int t_years)
    : m_initialAmount(t_initialAmount), m_monthlyDeposit(t_monthlyDeposit), m_interest(t_interest), m_years(t_years) {}


//OOP standard getters and setters, defined for the member variables in Account.h
double Account::getInitialAmount() const {
    return m_initialAmount;
}

void Account::setInitialAmount(double t_initialAmount) {
    m_initialAmount = t_initialAmount;
}

double Account::getMonthlyAmount() const {
    return m_monthlyDeposit;
}

void Account::setMonthlyAmount(double t_monthlyDeposit) {
    m_monthlyDeposit = t_monthlyDeposit;
}

double Account::getInterest() const {
    return m_interest;
}

void Account::setInterest(double t_interest) {
    m_interest = t_interest;
}

int Account::getYears() const {
    return m_years;
}

void Account::setYears(int t_years) {
    m_years = t_years;
}
