#include <iostream>
#include <set>

bool predicate(int lhs, int rhs) {
	return lhs > rhs;
}

int main()
{
	int count;
	std::cout << "Your count: ";
	std::cin >> count;
	std::set<int, decltype(&predicate)> my_set(predicate);
	for (int i = 0; i < count; i++) {
		std::cout << "your value: ";
		int temp;
		std::cin >> temp;
		my_set.insert(temp);
	}

	for (auto& el : my_set) {
		std::cout << el << std::endl;
	}

	return 0;
}