#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#include "..\FinanceTest2\Menu.hpp"
#include "..\FinanceTest2\Methods.hpp"
namespace UnitTests
{
	TEST_CLASS(FinanceTest)
	{
	public:

		TEST_METHOD(RegisterLoginTest)
		{
			Menu menu;
			Assert::IsFalse(menu.Login("Tess", "123"), L"Вход при 0 пользователей");
			Assert::IsTrue(menu.Register("Test", "123"), L"Создание пользователя");
			Assert::IsFalse(menu.Register("Test", "123"), L"Создание пользователя с таким же именем");
			Assert::IsFalse(menu.Login("Tess", "123"), L"Вход в несуществующего пользователя");
			Assert::IsTrue(menu.Login("Test", "123"), L"Вход в существующего пользователя");
		}

		TEST_METHOD(UserBalanceTest)
		{
			User testUser("Test", "123");
			Assert::IsTrue(testUser.GetBalance() == 0, L"При создании баланс не 0");
			Assert::IsTrue(testUser.GetLoan() == 0, L"При создании долг не 0");
			testUser.EditBalance(100);
			testUser.EditLoan(100);
			Assert::IsTrue(testUser.GetBalance() == 100, L"EditBalance не работает");
			Assert::IsTrue(testUser.GetLoan() == 100, L"EditLoan не работает");
		}

		TEST_METHOD(ConversionTest)
		{
			User testUser("Test", "123");
			Methods methods;
			testUser.EditBalance(100);
			//methods.Conversion(testUser, "Доллар");
			Assert::IsTrue(methods.Conversion(testUser, "Доллар") == 1.35, L"Conversion на доллар не работает");
			Assert::IsTrue(methods.Conversion(testUser, "Евро") == 1.15, L"Conversion на Евро не работает");
			Assert::IsTrue(methods.Conversion(testUser, "akusdfhs") == -1, L"Conversion на мусор выдаёт не -1");

		}
	};
}
