#include <iostream>

template<typename T>
struct SimpleSmartPointer
{
public:
	SimpleSmartPointer() {
		data = nullptr;
	}
	SimpleSmartPointer(T* data) : data{ data } {}
	~SimpleSmartPointer() {
		if (data) {
			delete data;
		}
	}

	SimpleSmartPointer(const SimpleSmartPointer& object) = delete;
	SimpleSmartPointer& operator=(SimpleSmartPointer& objcet) = delete;

	SimpleSmartPointer(SimpleSmartPointer&& objcet) noexcept : 
		data{ objcet.data }  
	{
		objcet.data = nullptr;
	}
	SimpleSmartPointer& operator=(SimpleSmartPointer&& objcet) noexcept
	{
		if (this == &objcet) return *this;
		if (data) {
			delete data;
			data = nullptr;
		}

		data = objcet.data;
		objcet.data = nullptr;
		return *this;
	}
	T* release() 
	{
		T* new_data = data;
		data = nullptr;

		return new_data;
	}

	T operator*()
	{
		return *data;
	}

private:
	T* data;
};

int main()
{
	SimpleSmartPointer<int> test(new int{ 23 });
	SimpleSmartPointer<int> test2;
	test2 = test.release();
	std::cout << *test2 << std::endl;
	return 0;
}