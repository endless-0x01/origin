#include <iostream>
#include <vector>
#include <algorithm>

template<class T>
T sqrt_for_me(T num)
{
	T result{};
	if (num < 0) {
		num = std::abs(num);
	}
	for (int i = 0; i < num; i++) {
		result += num;
	}
	return result;
}

template<class T> 
std::vector<T> sqrt_for_me(std::vector<T>& vec)
{
	std::vector<T> temp;
	for (auto num : vec) {
		temp.push_back(sqrt_for_me(num));
	}

	return temp;
}


int main()
{
	int a = sqrt_for_me(5);
	std::cout << a << std::endl;
	std::vector<int> vec{ -1,4,8 };
	std::vector<int> test = sqrt_for_me(vec);
	std::for_each(test.begin(), test.end(), [](int n) {std::cout << n << ", "; });
	return 0;
}