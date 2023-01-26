#include <iostream>
#include <string>

int simple_string_hash(const std::string& str)
{
	int hash{};
	for (int i = 0; i < str.size(); i++)
	{
		hash += str[i];
	}
	return hash;
}

int my_sqrt(int num, const int degree)
{
	int result = num;
	if (degree == 0)
		return 1;
	else if (degree == 1)
		return num;


	for (int i = 0; i < degree - 1; i++) {
		result = result * num;
	}
	return result;
}

int real_string_hash(const std::string& str, const int p, const int n)
{
	int hash{};
	int test{};
	int mult = 1;
	for (int i = 0; i < str.size(); i++)
	{
		hash = hash + my_sqrt(p, i) * str[i];
		std::cout << "hash = " << hash << std::endl;
	}



	return hash % 1000;
}

int main()
{
	setlocale(LC_ALL, "Ru");

	int p{};
	std::cout << "Введите P: ";
	std::cin >> p;
	std::cout << "Введите N: ";
	int n{};
	std::cin >> n;

	while (true) {
		std::cout << "Введите строку: ";
		std::string str;
		std::cin >> str;

		std::cout << "Наивный хэш строки " << str << " = " << real_string_hash(str, p, n) << std::endl;

		if (str == "exit")
			break;

	}

	return 0;
}