#include <iostream>
#include <vector>
#include <algorithm>

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

	std::for_each(vec.begin(), vec.end(),
		[](int el) {
			if (!(el % 2 == 0))
			std::cout << el * 3 << " ";
			else
				std::cout << el << " ";
		}
	);


	return 0;
}