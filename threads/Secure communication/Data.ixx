#include <iostream>
#include <mutex>
#include <random>
export module Data;


export class Data
{
public:
	Data() = default;
	Data(const int i) : value{ i } {}

	const int get_scalar_data() const{
		return value;
	}
	void set_scalar_data(const int data) {
		value = data;
	}

	std::mutex& get_mutex() {
		return mtx;
	}
private:
	std::mutex mtx;
	int value;
};

export void swap_base_mutex(Data& first, Data& second)
{
	first.get_mutex().lock();
	second.get_mutex().lock();

	int temp = first.get_scalar_data();
	first.set_scalar_data(second.get_scalar_data());
	second.set_scalar_data(temp);

	first.get_mutex().unlock();
	second.get_mutex().unlock();

}

export void swap_lock_guard(Data& first, Data& second)
{
	std::lock(first.get_mutex(), second.get_mutex());
	std::lock_guard<std::mutex>lock1{first.get_mutex(), std::adopt_lock};
	std::lock_guard<std::mutex>lock2{second.get_mutex(), std::adopt_lock};
	int temp = first.get_scalar_data();
	first.set_scalar_data(second.get_scalar_data());
	second.set_scalar_data(temp);
}

export void swap_uqnique_mutex(Data& first, Data& second)
{
	std::unique_lock<std::mutex>lock1{first.get_mutex(), std::defer_lock};
	std::unique_lock<std::mutex>lock2{second.get_mutex(), std::defer_lock};
	std::lock(lock1, lock2);

	int temp = first.get_scalar_data();
	first.set_scalar_data(second.get_scalar_data());
	second.set_scalar_data(temp);
}

export void swap_scoped_mutex(Data& first, Data& second)
{
	std::scoped_lock(first.get_mutex(), second.get_mutex());

	int temp = first.get_scalar_data();
	first.set_scalar_data(second.get_scalar_data());
	second.set_scalar_data(temp);
}

export bool simulate_error() {
	std::srand(time(NULL));
	int r_value = rand() % 100;
	return r_value < 30;
}

export void showProgressBar(int progress, bool hasError) {
	const int barWidth = 50;
	std::string colorCode = (hasError) ? "\x1B[31m" : ""; 
	std::string resetColorCode = "\x1B[0m"; 
	std::cout << colorCode << "[";
	int pos = barWidth * progress / 100;
	for (int i = 0; i < barWidth; ++i) {
		if (i < pos)
			std::cout << "=";
		else if (i == pos)
			std::cout << ">";
		else
			std::cout << " ";
	}
	std::cout << "] " << progress << "%" << resetColorCode << std::endl;
}
