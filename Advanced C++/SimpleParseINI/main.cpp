#include "Parser.h"

int main()
{
	setlocale(LC_ALL, "Ru");

	try {
		Parser parser("ini.txt");
		auto value = parser.get_value<int>("Section2.var1");
		std::cout << value << std::endl;
	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}