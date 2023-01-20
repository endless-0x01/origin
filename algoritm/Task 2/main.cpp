#include <iostream>


struct my_vector
{
private:
	int* arr = nullptr;
	int actual_size_arr{};
	int logical_size_arr{};
public:
	my_vector(int size_a, int size_l) :
		actual_size_arr(size_a), logical_size_arr(size_l) {

		if (actual_size_arr < logical_size_arr) {
			throw std::exception("Ошибка! Логический размер массива не может превышать фактический!");
		}
		arr = new int[actual_size_arr] {};
	}

	~my_vector() {
		delete[] arr;
		arr = nullptr;
	}


	void fill_arr() {
		for (int i = 0; i < logical_size_arr; i++)
		{
			std::cout << "Введите arr[" << i << "]: ";
			int num{};
			std::cin >> num;
			arr[i] = num;
		}
	}

	void print_dynamic_array()
	{
		for (int i = 0; i < actual_size_arr; i++)
		{
			if (i < logical_size_arr)
				std::cout << arr[i] << " ";
			else
				std::cout << "_ ";
		}

		std::cout << std::endl;
	}
};


int main()
{
	setlocale(LC_ALL, "Ru");

	try {
		int actual_s{};
		std::cout << "Введите фактичеcкий размер массива: ";
		std::cin >> actual_s;

		int logical_s{};
		std::cout << "Введите логический размер массива: ";
		std::cin >> logical_s;

		my_vector arr(actual_s, logical_s);
		arr.fill_arr();
		arr.print_dynamic_array();

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}
