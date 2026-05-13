#pragma once
#include "Header.hpp"
#include "Methods.hpp"
#include "User.hpp"
class Menu
{
public:

	Menu()
	{

	}

	bool Login(std::string name, std::string password)
	{
		if (users.size() > 0)
		{
			for (int i = 0; i < users.size(); i++)
			{
				if (users[i].GetName() == name && users[i].GetPassword() == password)
				{
					currentUser = users[i];
					return true;
				}
			}
			std::cout << "Неверный логин или пароль\n";
			return false;
		}
		std::cout << "Нет пользователей\n";
		return false;
	}
	void LoginInterface()
	{

	}
	void MenuInterface()
	{

	}

	bool Register(std::string name, std::string password)
	{
		if (users.size() > 0)
		{
			for (int i = 0; i < users.size(); i++)
			{
				if (users[i].GetName() == name)
				{
					std::cout << "Пользователь с таким именем уже существует\n";
					return false;
				}
			}
			users.push_back(User(name, password));
			currentUser = users[users.size() - 1];
			return true;
		}
		users.push_back(User(name, password));
		currentUser = users[users.size() - 1];
		return true;
	}

	void RegisterInterface()
	{

	}

private:
	User currentUser;
	std::vector<User> users;
};

