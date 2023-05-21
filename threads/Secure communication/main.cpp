#include <iostream>
#include <thread>
#include <chrono>
import Data;

int main()
{
	Data object1{ 10 };
	Data object2{ 20 };

	int progress{};
	while (progress < 100)
	{
		swap_base_mutex(object1, object2);
		std::cout << "Data 1 after swap (with lock): " << object1.get_scalar_data() << std::endl;
		std::cout << "Data 2 after swap (with lock): " << object2.get_scalar_data() << std::endl;

		swap_lock_guard(object1, object2);
		std::cout << "Data 1 after swap (with lock_guard): " << object1.get_scalar_data() << std::endl;
		std::cout << "Data 2 after swap (with lock_guard): " << object2.get_scalar_data() << std::endl;

		swap_uqnique_mutex(object1, object2);
		std::cout << "Data 1 after swap (with unique_guard): " << object1.get_scalar_data() << std::endl;
		std::cout << "Data 2 after swap (with unique_guard): " << object2.get_scalar_data() << std::endl;

		swap_scoped_mutex(object1, object2);
		std::cout << "Data 1 after swap (with scoped_mutex): " << object1.get_scalar_data() << std::endl;
		std::cout << "Data 2 after swap (with scoped_mutex): " << object2.get_scalar_data() << std::endl;

		bool hasError = simulate_error();
		if (hasError) {
			std::cout << "Error!" << std::endl;
		}
		showProgressBar(progress, hasError);
		++progress;

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	return 0;
}
