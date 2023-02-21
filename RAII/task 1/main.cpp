#include <iostream>

struct SmartArr
{
public:
	SmartArr(size_t count_element)
		: _max_size(count_element), _index{} {
		
		if (_max_size == 0) {
			throw std::runtime_error("Max size must be last 1");
		}

		_arr = new int[_max_size] {};
	}
	SmartArr(const SmartArr& other)
		:_max_size{ other._max_size }, _index{ other._index },	_arr{ new int[other._max_size] {} } {

		for (int i = 0; i < _index; i++)
		{
			_arr[i] = other._arr[i];
		}
	}

	SmartArr& operator=(const SmartArr& other)
	{
		if (this == &other) return *this;
		const auto new_buffer = new int[other._max_size];
		delete[] _arr;
		_arr = nullptr;

		_max_size = other._max_size;
		_index = other._index;
		_arr = new_buffer;


		for (int i = 0; i < _index; i++)
		{
			_arr[i] = other._arr[i];
		}

		return *this;
	}

	~SmartArr() {
		std::cout << "Destroyed object" << std::endl; // for test...
		delete[] _arr;
		_arr = nullptr;
	}

	void print_arr() const {
		for (int i = 0; i < _index; i++) {
			std::cout << _arr[i] << ", ";
		}
		std::cout << "\n";
	}
	const int get_element(int i) const {
		if (i >= _index) {
			throw std::runtime_error("index exceeds array size");
		}
		return _arr[i];
	}
	void add_element(const int element)
	{
		if (_index >= _max_size) {
			throw std::runtime_error("Out of allocated memory for array");
		}
		_arr[_index++] = element;
	}
private:
	size_t _max_size;
	unsigned int _index;
	int* _arr;
};


int main()
{
	try {
		SmartArr arr(7);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);

		SmartArr new_arr{ arr };
		arr.print_arr();
		new_arr.add_element(43);
		new_arr.print_arr();

		SmartArr new_arr_three{10};
		new_arr_three = new_arr;
		new_arr_three.print_arr();

		new_arr_three.add_element(1234);


		std::cout << arr.get_element(3) << std::endl;


		std::cout << "Ending show all arr: \n";
		arr.print_arr();
		new_arr.print_arr();
		new_arr_three.print_arr();
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}