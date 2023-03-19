#include <iostream>
#include <string>
#include <algorithm>

struct big_intenger
{
public:
	big_intenger(std::string num) : number{ num } {}

	big_intenger(big_intenger&& other) noexcept :
		number{other.number}
	{
		other.number = "0";
	}
	big_intenger& operator=(big_intenger&& other) noexcept {
		if (this == &other) return *this;
		number = other.number;
		other.number = "0";
	}

	big_intenger operator+(big_intenger& other) {

		number.length() < other.number.length() ?
			stand_null(number, number.length() - other.number.length()) : stand_null(other.number, number.length() - other.number.length());
		std::string result;
		for (size_t i = 0; i < number.length(); i++) {


			int res = (number[i] - '0') + (other.number[i] - '0');
			if (res > 9) {
				res = res % 10;
				result += std::to_string(res);
				int index = i - 1;
				int h_r = (result[index] - '0') + 1;
				result[index] = h_r + '0';
			}
			else
			{
				result += std::to_string(res);
			}

		}

		return { result };
	}


	big_intenger operator*(big_intenger& other) {

		number.length() < other.number.length() ?
			stand_null(number, number.length() - other.number.length()) : stand_null(other.number, number.length() - other.number.length());
		std::string result;

		for (size_t i = 0; i <= number.length(); i++) {



			int res = (number[i] - '0') * (other.number[i] - '0');
			if (res > 9) {
				res = res % 10;
				result += std::to_string(res);
				int index = i - 1;
				int h_r = (result[index] - '0') + 1;
				result[index] = h_r + '0';
			}
			else
			{
				result += std::to_string(res);
			}

		}
		return { result };
	}


	const std::string get_num() const{
		return number;
	}

	const size_t get_size() {
		return number.length();
	}

private:
	void stand_null(std::string& num, int different) {

		for (int i = 0; i < different; i++) {
			num = '0' + num;
		}
	}

	std::string number;
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

	auto number3 = big_intenger("2");
	auto number4 = big_intenger("10");
	auto result5 = number3 * number4;
	std::cout << result5; // 20

	return 0;
}