#include <iostream>
#include <fstream>

int* get_ram(int size) {
	return static_cast<int*>(malloc(sizeof(int) * size));
}

void fill_arr(std::ifstream& in,int* arr, const int size)
{
	for (int i = 0; i < size; i++) {
		in >> arr[i];
	}
}

void shift_right(int* arr, const int size)
{
	int temp = arr[0];
	for (int i = 0; i < size - 1; i++)
	{
		arr[i] = arr[i + 1];
	}

	arr[size - 1] = temp;
}
void shift_left(int* arr, const int size)
{
	int temp = arr[size - 1];

	for (int i = size; i > 0; i--)
	{
		arr[i] = arr[i - 1];
	}

	arr[0] = temp;
}


int main()
{
	int size_arr_first{};
	int size_arr_second{};

	std::ifstream in("D:\\netology\\Lessons 1\\IntroductionToIDE\\in.txt");
	if (in.fail()) {
		std::cout << "Faile open fail!" << std::endl;
		exit(-1);
	}

	
	in >> size_arr_first;
	int* arr_first = get_ram(size_arr_first);
	fill_arr(in, arr_first, size_arr_first);


	in >> size_arr_second;
	int* arr_second = get_ram(size_arr_second);
	fill_arr(in, arr_second, size_arr_second);

	in.close();
	
	shift_right(arr_first, size_arr_first);
	shift_left(arr_second, size_arr_second);

	std::ofstream out("data.txt");

	out << size_arr_second << "\n";
	for (int i = 0; i < size_arr_second; i++)
		out << arr_second[i] << " ";
	out << "\n";

	out << size_arr_first << "\n";
	for (int i = 0; i < size_arr_first; i++)
		out << arr_first[i] << " ";
	out << "\n";

	free(arr_first);
	free(arr_second);

	return 0;
}