#include <iostream>
#include <vector>

int main()
{
	setlocale(LC_ALL, "Ru");

	std::vector<int> vec{ 4, 7, 9, 14, 12 };
	std::cout << "Входные данные: ";
	for (const auto& i : vec) {
		std::cout << i << " ";
	}
	std::cout << "\n";

	std::cout << "Выходные данные: ";
	auto func = [&vec]() {
		for (const auto& i : vec) {
			if(!(i % 2 == 0))
				std::cout << i * 3 << " ";
			else
				std::cout << i << " ";
		}
		std::cout << "\n";
	};

	func();

	return 0;
}