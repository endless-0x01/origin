#include <iostream>
#include <Windows.h>

int function(const std::string& str,const int forbidden_length)
{
	const size_t str_size = str.size();
	if (str_size > forbidden_length)
		throw std::length_error("Error: forbidden length exceeded");
	return str_size;
}

int main()
{
	setlocale(LC_ALL, "Ru");
	SetConsoleCP(1251);
	try
	{
		int forbidden_length{};
		std::cout << "������� ��������� �����: ";
		std::cin >> forbidden_length;
		while (true)
		{
			std::string str;
			std::cout << "������� �����: ";
			std::cin >> str;
			std::cout << "������ �����: " << str << " ����� " << function(str, forbidden_length) << std::endl;
		}
	}
	catch (std::length_error& le)
	{
		std::cerr << le.what() << std::endl;
	}
	return 0;
}