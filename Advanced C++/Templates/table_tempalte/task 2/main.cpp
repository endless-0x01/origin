#include <iostream>

template<class T>
struct simple_doule_arr
{
public:
	simple_doule_arr() : row{ 0 }, col{ 0 }, arr{ nullptr } {}
	simple_doule_arr(const int row, const int col) :
		row{ row }, col{ col } {

		if (row == 0 || col == 0)
			throw std::runtime_error("value to be accepted");
		arr = new T * [row];
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

	simple_doule_arr(simple_doule_arr& other) :
		row{ other.row }, col{ other.col }
	{
		// Сделал через malloc для повторения материала
		arr = static_cast<T**>(malloc(row * sizeof(T*)));
		for (int i = 0; i < row; i++) {
			arr[i] = static_cast<T*>(malloc(col * sizeof(T*)));
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				arr[i][j] = other.arr[i][j];
			}
		}
	}

	simple_doule_arr(simple_doule_arr&& other) noexcept
		: row{ other.row }, col{ other.col }, arr{ other.arr }
	{
		other.row = 0;
		other.col = 0;
		other.arr = nullptr;
	}

	simple_doule_arr& operator=(simple_doule_arr& other)
	{
		if (this == &other)	return *this;

		row = other.row;
		col = other.col;

		auto new_arr = static_cast<T**>(malloc(row * sizeof(T*)));

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				new_arr[i] = static_cast<T*>(malloc(col * sizeof(T*)));
			}
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				new_arr[i][j] = other[i][j];
			}
		}

		arr = new_arr;

		return *this;
	}

	simple_doule_arr& operator=(simple_doule_arr&& other) noexcept
	{
		if (this == &other) return *this;

		if (arr != nullptr)
			this->~simple_doule_arr();

		row = other.row;
		col = other.col;
		arr = other.arr;

		other.row = 0;
		other.col = 0;
		other.arr = nullptr;

		return *this;
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
	simple_doule_arr<int> test;
	test = std::move(arr);
	//std::cout << "Main arr: " << arr.Size() << std::endl;
	std::cout << "Test arr: " << test.Size() << std::endl;
	//arr[0][0] = 4;
	test[0][0] = 20;
	//std::cout << "Main value: " << arr[0][0] << std::endl;
	std::cout << "Test value: " << test[0][0] << std::endl;
	return 0;
}