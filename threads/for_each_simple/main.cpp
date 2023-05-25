#include <iostream>
#include <future>
#include <vector>
#include <algorithm>
#include <random>

void PrintNumber(const int& x) {
	x < 10 ? std::cout << x << std::endl : std::cout << "";
}

template<typename Iter, typename F>
void ParallelForEach(Iter start, Iter end, F f)
{
	const int size = std::distance(start, end);
	const int threshold = 1000;
	if (size <= threshold) {
		std::for_each(start, end, f);
	}
	else {
		auto middle = start + (size / 2);
		auto ft1 = std::async(std::launch::async, ParallelForEach<Iter, F>, start, middle, f);
		auto ft2 = std::async(std::launch::async, ParallelForEach<Iter, F>, middle, end, f);

		ft1.wait();
		ft2.wait();
	}
}

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 100000);

	std::vector<int> vec(100000);
	std::generate(vec.begin(), vec.end(), [&]() {return dis(gen); });

	ParallelForEach(vec.begin(), vec.end(), PrintNumber);

	return 0;
}