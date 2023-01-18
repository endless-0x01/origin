#include <iostream>
#include <algorithm>
#include <iterator>

void mergeSort(int* arr, int n)
{
	if (n > 1)
	{
		const int left_size = n / 2;
		const int right_size = n - left_size;

		mergeSort(&arr[0], left_size);
		mergeSort(&arr[left_size], right_size);

		int lidx = 0, ridx = left_size, idx = 0;

		std::unique_ptr<int[]> tmp_arr(new int[n]);

		while (lidx < left_size || ridx < n)
		{
			if (arr[lidx] > arr[ridx])
			{
				tmp_arr[idx++] = std::move(arr[ridx]);
				ridx += 1;
			}
			else
			{
				tmp_arr[idx++] = std::move(arr[lidx]);
				lidx += 1;
			}

			if (lidx == left_size)
			{
				std::copy(std::make_move_iterator(&arr[ridx]), std::make_move_iterator(&arr[n]),
					&tmp_arr[idx]);
				break;
			}
			if (ridx == n)
			{
				std::copy(std::make_move_iterator(&arr[lidx]), std::make_move_iterator(&arr[left_size]),
					&tmp_arr[idx]);
				break;
			}
		}

		std::copy(&tmp_arr[0], &tmp_arr[n], arr);
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;
}

int main()
{
	{
		int arr[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
		const int size = sizeof(arr) / sizeof(int);
		mergeSort(arr, size);
		std::cout << std::endl;
	}


	return 0;
}