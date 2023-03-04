#include <iostream>
#include <vector>


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
void sqrt_for_me(std::vector<T>& vec)
{
	for (auto& num : vec) {
		num = sqrt_for_me(num);
	}
}


int main()
{
	std::cout << sqrt_for_me(4) << std::endl;
	std::vector<int> vec{ -1,4,8 };
	sqrt_for_me(vec);
	for (auto& i : vec) {
		std::cout << i << " ";
	}
	return 0;
}