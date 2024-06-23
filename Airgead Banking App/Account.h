#ifndef ACCOUNT_H
#define ACCOUNT_H

//simple header file to describe the account class
class Account {
	//private members
	private:
		double m_initialAmount;
		double m_monthlyDeposit;
		double m_interest;
		int m_years;

	//public member functions and all arg and no arg constructor
	public:
		Account();
		Account(double t_initalAmmount, double t_monthlyDeposit,
			double t_interest, int t_years);

		double getInitialAmount() const;
		void setInitialAmount(double t_initalAmmount);
		double getMonthlyAmount() const;
		void setMonthlyAmount(double t_MonthlyAmount);
		double getInterest() const;
		void setInterest(double t_interest);
		int getYears() const;
		void setYears(int t_years);
};

#endif // !ACCOUNT_H