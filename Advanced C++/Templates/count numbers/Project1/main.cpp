#include <iostream>
#include <vector>
#include <algorithm>

struct simple_functor
{
public:
	simple_functor() = default;

	void operator()(int num) {
		if (num % 3 == 0) {
			countNumber++;
			sumNumbers += num;
		}

	}

	const int get_sum() {
		return sumNumbers;
	}
	const int get_count() {
		return countNumber;
	}

private:
	int countNumber{};
	int sumNumbers{};
}sf;


int main() {

	std::vector<int> vec {4, 1, 3, 6, 25, 54};
	std::for_each(vec.begin(), vec.end(), [](const int& n) { sf(n); });
	
	std::cout << "Count: " << sf.get_count() << " | Sum: " << sf.get_sum() << std::endl;

	return 0;
}