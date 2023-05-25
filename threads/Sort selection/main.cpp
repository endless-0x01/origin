#include <iostream>
#include <future>
#include <vector>
#include <thread>
#include <random>
#include <mutex>
#include <algorithm>


void FillingVector(std::vector<int>& vec)
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> dis(0, 100);

	for (int i = 0; i < 10; i++) {
		vec.push_back(dis(generator));
	}
}

namespace proccesing_method {
	namespace future_and_promise {
		void FindMinElement(std::promise<int>&& prm, std::vector<int>::iterator begin,
			std::vector<int>::iterator end)
		{
			prm.set_value(*std::min_element(begin, end));
		}

		void SortingSelection(std::vector<int>& vec)
		{
			std::vector<std::thread> threads;
			for (auto it = vec.begin(); it < vec.end(); it++)
			{
				std::promise<int> prm;
				std::future<int> ftr = prm.get_future();
				threads.emplace_back(FindMinElement, std::move(prm), it, vec.end());

				if (ftr.wait_for(std::chrono::milliseconds(500)) == std::future_status::ready) {
					int min_value = ftr.get();
					auto min_pos = std::find(it, vec.end(), min_value);
					std::iter_swap(it, min_pos);
				}

			}
			for (auto& t : threads) {
				t.join();
			}
		}
	}
	namespace async_method {
		void SortingSelection(std::vector<int>& vec) {
			for (auto it = vec.begin(); it != vec.end(); it++) 
			{
				std::future<int> ftr = std::async(std::launch::async, [&]() {return *std::min_element(it, vec.end()); });
				if (ftr.wait_for(std::chrono::milliseconds(500)) == std::future_status::ready)
				{
					int min_value = ftr.get();
					auto min_pos = std::find(it, vec.end(), min_value);
					std::iter_swap(it, min_pos);
				}
			}
		}
	}
}


int main()
{
	std::vector<int> vec;
	FillingVector(vec);
	std::cout << "No sorting vector: " << std::endl;
	for (auto& el : vec) {
		std::cout << el << " ";
	} 
	std::cout << "\n";

	//proccesing_method::future_and_promise::SortingSelection(vec);
	proccesing_method::async_method::SortingSelection(vec);
	std::cout << "After sorting vector: " << std::endl;
	for (auto& el : vec) {
		std::cout << el << " ";
	}
	std::cout << "\n";
	return 0;
}