#include <iostream>

int count_elemnt_max(int* arr, int size, int x)
{
	int left = 0;
	int right = size - 1;

	int count_elemnt{};


	while (left < right)
	{
		int middle = (left + right) / 2;

		if (arr[middle] == x) {
			for (int i = middle + 1; i <= right; i++) {
				if (arr[i] != x) {
					count_elemnt++;
				}
			}
			break;
		}
		else if (arr[middle] > x)
		{
			right = middle - 1;
		}
		else if (arr[middle] < x)
		{
			left = middle + 1;
		}

	}

	if (arr[left] == x)
	{
		for (int i = left + 1; i < size; i++) {
			count_elemnt++;
		}
	}
	else if (arr[left] < x && arr[left + 1] > x) {
		for (int i = 1; i < size; i++) {
			count_elemnt++;
		}
	}
	return count_elemnt;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };

	std::cout << "Введите точку отсчета: ";
	int num{};
	std::cin >> num;

	std::cout << "Количество элементов в массиве больших, чем " << num << ": "
		<< count_elemnt_max(arr, sizeof(arr) / sizeof(int), num) << std::endl;

	return 0;
}