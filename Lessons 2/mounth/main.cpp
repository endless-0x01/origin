#include <iostream>

enum class Mount
{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December,
};

int main()
{
	setlocale(LC_ALL, "Ru");

	while (true) {
		std::cout << "Введите номер месяца: ";
		int n_mounth{};
		std::cin >> n_mounth;
		if (!n_mounth) {
			std::cout << "До свидания!\n";
			exit(0);
		}
		switch (static_cast<Mount>(n_mounth))
		{
		case Mount::January: std::cout << "Январь" << std::endl; break;
		case Mount::February: std::cout << "Февраль" << std::endl; break;
		case Mount::March: std::cout << "Март" << std::endl; break;
		case Mount::April: std::cout << "Апрель" << std::endl; break;
		case Mount::May: std::cout << "Май" << std::endl; break;
		case Mount::June: std::cout << "Июнь" << std::endl; break;
		case Mount::July: std::cout << "Июль" << std::endl; break;
		case Mount::August: std::cout << "Август" << std::endl; break;
		case Mount::September: std::cout << "Сентябрь" << std::endl; break;
		case Mount::October: std::cout << "Октябрь" << std::endl; break;
		case Mount::November: std::cout << "Ноябрь" << std::endl; break;
		case Mount::December: std::cout << "Декабрь" << std::endl; break;

		default:
			std::cout << "Такого месяца нет..." << std::endl;
			break;
		}
	}

	return 0;
}