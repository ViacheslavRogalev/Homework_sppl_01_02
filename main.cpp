#include <iostream>
#include <string>
#include <vector>
#include <variant>
#include <algorithm>

std::variant<int, std::string, std::vector<int>> get_variant()
{
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");

	if (std::holds_alternative<int>(get_variant()) == 1)
	{
		std::cout << std::get<int>(get_variant()) * 2 << std::endl;
	}
	else if (std::holds_alternative<std::string>(get_variant()) == 1)
	{
		std::cout << std::get<std::string>(get_variant()) << std::endl;
	}
	else if (std::holds_alternative<std::vector<int>>(get_variant()) == 1)
	{
		std::vector<int> myVector = std::get<std::vector<int>>(get_variant());

		std::for_each(myVector.begin(), myVector.end(), [](const int& n) {std::cout << n << '\t'; });
	}
	else
	{
		std::cout << "Нет такого типа данных" << std::endl;
	}
}