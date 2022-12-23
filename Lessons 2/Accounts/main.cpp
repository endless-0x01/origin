#include <iostream>
#include <string>


struct Accounts {
	int num_acc{};
	std::string name_u;
	double cash{};
};

int main()
{
	setlocale(LC_ALL, "ru");
	Accounts ac;
	std::cout << "Введите номер счёта: ";
	std::cin >> ac.num_acc;
	std::cout << "Введите имя владельца: ";
	std::cin >> ac.name_u;
	std::cout << "Введите баланс: ";
	std::cin >> ac.cash;
	std::cout << "Введите новый баланс: ";
	std::cin >> ac.cash;
	std::cout << "Ваш счёт: " << ac.name_u << ", " << ac.num_acc << ", " << ac.cash << std::endl;
	return 0;
}