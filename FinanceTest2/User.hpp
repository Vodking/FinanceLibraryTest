#pragma once
#include "Header.hpp"

class User
{
public:
	User(std::string name, std::string password)
	{
		_name = name;
		_password = password;
		_balance = 0;
		_loan = 0;
	}

	User()
	{

	}

	std::string GetName()
	{
		return _name;
	}

	std::string GetPassword()
	{
		return _password;
	}

	double GetBalance()
	{
		return _balance;
	}

	double GetLoan()
	{
		return _loan;
	}

	bool EditBalance(double num)
	{
		_balance += num;
		return true;
	}

	bool EditLoan(double num)
	{
		_loan += num;
		return true;
	}
private:
	std::string _name;
	std::string _password;

	double _balance;
	double _loan;
};

