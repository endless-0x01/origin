#include <iostream>

template<class T>
struct simple_doule_arr
{
public:
	simple_doule_arr(const int row, const int col) :
		row{ row }, col{ col } {
		
		if (row == 0 || col == 0)
			throw std::runtime_error("value to be accepted");
		arr = new T*[row];
		for (int i = 0; i < row; i++) {
			arr[i] = new T[col]{};
		}
	}
	~simple_doule_arr() {
		
		for (int i = 0; i < row; i++) {
			delete arr[i];
			arr[i] = nullptr;
		}
		delete[] arr;
	}

	T* operator[](const int i) {
		return arr[i];
	}

	const T* operator[](const int i) const {
		return arr[i];
	}

	const int Size() const {
		return row + col;
	}

private:
	int row;
	int col;
	T** arr;
};


int main()
{
	simple_doule_arr<int> arr(2, 3);
	std::cout << arr.Size() << std::endl;
	arr[0][0] = 4;
	std::cout << arr[0][0] << std::endl;
	return 0;
}