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

int main()
{
	setlocale(LC_ALL, "Ru");

	while (true) {
		std::cout << "������� ������: ";
		std::string str;
		std::cin >> str;

		std::cout << "������� ��� ������ " << str << " = " << simple_string_hash(str) << std::endl;

		if (str == "exit")
			break;

	}

	return 0;
}