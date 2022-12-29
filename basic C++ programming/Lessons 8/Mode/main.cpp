#include <iostream>

#define MODE 1

#ifndef MODE
#error we should define MODE
#endif // !MODE


int main()
{
	setlocale(LC_ALL, "Ru");
#if MODE == 0
	std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE == 1

#define add(a, b) (a) + (b)
	std::cout << "Работаю в боевом режиме!" << std::endl;
	std::cout << "Введите число 1: ";
	int a{};
	std::cin >> a;

	std::cout << "Введите число 2: ";
	int b{};
	std::cin >> b;

	std::cout << "Результат cложения: " << add(a, b) << std::endl;

#else
	std::cout << "Неизвестный режим. Завершение работы" << std::endl;
#endif
}