#include <iostream>
#include <initializer_list>

template<typename T>
struct my_vecotr
{
public:
	my_vecotr() : size_{ 1 }, capacity_{ 1 }, arr_{ new T[1]{} } {}
	my_vecotr(std::initializer_list<T> data) :
		size_{ data.size() }, capacity_{ data.size() * 2 }, arr_{ new T[data.size() * 2]{}}
	{
		std::copy(data.begin(), data.end(), arr_);
	}
	~my_vecotr() {
		delete[] arr_;
		arr_ = nullptr;
		size_ = 0, capacity_ = 0;
	}

	my_vecotr(const my_vecotr& object)
		: size_{ object.size_ }, capacity_{ object.capacity_ }, arr_{new T[object.capacity_]}
	{
		std::copy(&object.arr_[0], &object.arr_[object.capacity_], arr_);
	}
	my_vecotr& operator=(my_vecotr& object)
	{
		if (this == &object) return *this;

		free_memory();

		size_ = object.size_;
		capacity_ = object.capacity_;
		arr_ = new T[capacity_];
		std::copy(&object.arr_[0], &object.arr_[object.capacity_], arr_);

		return *this;
	}
	my_vecotr(my_vecotr&& objcet) noexcept = delete;
	my_vecotr operator=(my_vecotr&& object) noexcept = delete;


	void show_data() {
		for (int i = 0; i < size_; i++) {
			std::cout << arr_[i] << " ";
		}
		std::cout << "\n";
	}

	void push_back(T value) {
		
		if (check_size_for_added()) {
			arr_[size_++] = value;
		}
		else {
			add_memory();
			arr_[size_++] = value;
		}
	}

	size_t size() {
		return size_;
	}

	size_t capacity() {
		return capacity_ - size_;
	}

	T at(int index) {
		if (index < 0 || index > size_)
			throw std::runtime_error("search index is larger than size");

		return arr_[index];
	}
private:
	void free_memory() {
		delete[] this->arr_;
		size_ = 0, capacity_ = 0;
	}

	void add_memory() {
		capacity_ *= 2;
		T* temp_arr = arr_;
		arr_ = new T[capacity_];
		for (int i = 0; i < size_; i++)
		{
			arr_[i] = temp_arr[i];
		}

		delete[] temp_arr;
	}
	bool check_size_for_added() {
		if (size_ >= capacity_) {
			return false;
		}
		else {
			return true;
		}
	}
private:
	T* arr_;
	size_t size_;
	size_t capacity_;
};


int main()
{
	try {
		my_vecotr<int> vec{ 1,2 };
		int a = vec.at(0);
		vec.push_back(182);
		vec.push_back(99);
		vec.push_back(100);
		std::cout << vec.capacity() << std::endl;
		std::cout << vec.size() << std::endl;
		vec.show_data();
		my_vecotr<int> vec_2{ vec };
		//vec = std::move(vec_2);
		vec_2.show_data();
		my_vecotr<int> test{ 3,4,5,6 };
		test.show_data();
		test = vec_2;
		test.show_data();

		my_vecotr<int> r;
		r = test;

		r.show_data();
		std::cout << &vec << " " << &vec_2 << " " << &test << std::endl;
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
};
	