#pragma once
#include "Header.hpp"
#include "User.hpp"
class Methods
{
public:

	Methods()
	{

	}

	void LoanInterface(User user)
	{

	}

	void ConversionInterface(User user)
	{

	}

	void BalanceInterface(User user)
	{

	}


	double Conversion(User user, std::string moneyName)
	{
		if (moneyName == "Доллар")
		{
			return std::round(user.GetBalance() / 73.83 * 100) / 100;
		}
		else if (moneyName == "Евро")
		{
			return std::round(user.GetBalance() / 86.63 * 100) / 100;
		}
		else
		{
			return -1;
		}
	}

private:

	bool AddBalance(User user, double num)
	{
		if (num < 0)
		{
			std::cout << "Нельзя положить отрицательно денег";
			return false;
		}
		user.EditBalance(num);
		return true;
	}

	bool TakeBalance(User user, double num)
	{
		if (num < user.GetBalance())
		{
			user.EditBalance(-num);
			return true;
		}
		else
		{
			std::cout << "Недостаточно средств!";
			return false;
		}

	}




	bool TakeLoan()
	{

		return true;
	}
	
	bool PayLoan()
	{
		return true;
	}
};

