#include "libs.h"
#include "data.h"
#include "math.h"

int main()
{
	setlocale(LC_ALL, "ru");
	
	std::cout << "Введите первое число: ";
	int first_number = get_number();
	std::cout << "Введите второе число: ";
	int second_number = get_number();

	math(first_number, second_number);

	return 0;
}