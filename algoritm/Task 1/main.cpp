#include <iostream>
#include <algorithm>
#include <iterator>

//void mergeSort(int* arr, int n)
//{
//	if (n > 1)
//	{
//		const int left_size = n / 2;
//		const int right_size = n - left_size;
//
//		mergeSort(&arr[0], left_size);
//		mergeSort(&arr[left_size], right_size);
//
//		int lidx = 0, ridx = left_size, idx = 0;
//
//		std::unique_ptr<int[]> tmp_arr(new int[n]);
//
//		while (lidx < left_size || ridx < n)
//		{
//			if (arr[lidx] > arr[ridx])
//			{
//				tmp_arr[idx++] = std::move(arr[ridx]);
//				ridx += 1;
//			}
//			else
//			{
//				tmp_arr[idx++] = std::move(arr[lidx]);
//				lidx += 1;
//			}
//
//			if (lidx == left_size)
//			{
//				std::copy(std::make_move_iterator(&arr[ridx]), std::make_move_iterator(&arr[n]),
//					&tmp_arr[idx]);
//				break;
//			}
//			if (ridx == n)
//			{
//				std::copy(std::make_move_iterator(&arr[lidx]), std::make_move_iterator(&arr[left_size]),
//					&tmp_arr[idx]);
//				break;
//			}
//		}
//
//		std::copy(&tmp_arr[0], &tmp_arr[n], arr);
//	}
//	
//	for (int i = 0; i < n; i++)
//	{
//		std::cout << arr[i] << ", ";
//	}
//	std::cout << std::endl;
//}

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
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}











	//{
	//	int arr[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
	//	const int size = sizeof(arr) / sizeof(int);
	//	mergeSort(arr, size);
	//	std::cout << std::endl;
	//}

	return 0;
}