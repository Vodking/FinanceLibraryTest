#include "Menu.hpp"
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu menu;
	User testUser("Test", "123");
	Methods methods;
	menu.Login("Test", "123");
	menu.Register("Test", "123");
	menu.Register("Test", "123");
	testUser.EditBalance(100);
	std::cout << methods.Conversion(testUser, "Евро");
}