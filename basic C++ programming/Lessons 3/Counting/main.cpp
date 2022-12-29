#include <iostream>
#include <string>
#include <Windows.h>
class Counting
{
private:
	int count;
public:
	Counting() : count(1) {}
	Counting(int st_c) : count(st_c) {}

	Counting& operator++() {
		count++;
		return *this;
	}

	Counting& operator--() {
		count--;
		return *this;
	}

	const int get_count()  {
		return count;
	}
};

int main()
{
	setlocale(LC_ALL, "Ru");
	SetConsoleCP(1251);

	Counting ct;
	std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	std::string ch;
	std::cin >> ch;
	if (ch == "да") {
		int st_n{};
		std::cout << "Введите начальное значения счетчика: ";
		std::cin >> st_n;
	}

	while (true) {
		std::cout << "Введите команду ('+', '-', '=' иди 'x'): ";
		char ch{};
		std::cin >> ch;
		switch (ch)
		{
		case '+': ct.operator++(); break;
		case '-': ct.operator--(); break;
		case '=': std::cout << ct.get_count() << "\n"; break;
		case 'x': std::cout << "До свидания!" << std::endl; return 0;
		default:
			break;
		}
	}

	return 0;
}