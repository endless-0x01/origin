#include <iostream>
#include <string>

struct big_intenger
{
public:
	big_intenger(std::string num)
	{
		number = std::atoll(num.c_str());
	}

	big_intenger(big_intenger&& other) noexcept :
		number{other.number}
	{
		other.number = 0;
	}
	big_intenger& operator=(big_intenger&& other) noexcept {
		if (this == &other) return *this;
		number = other.number;
		other.number = 0;
	}

	big_intenger operator+(const big_intenger& other) {
		return big_intenger(std::to_string(number + other.number));
	}

	big_intenger operator*(const big_intenger& other) {
		return big_intenger(std::to_string(number * other.number));
	}

	const long long get_num() const{
		return number;
	}

private:
	long long number;
};

std::ostream& operator<<(std::ostream& os, const big_intenger& object)
{
	return os << object.get_num() << std::endl;
}

int main()
{
	auto number1 = big_intenger("114575");
	auto number2 = big_intenger("78524");
	auto result = number1 + number2;
	std::cout << result; // 193099

	return 0;
}