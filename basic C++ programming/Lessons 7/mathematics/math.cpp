#include "libs.h"
#include "data.h"
#include "math.h"

void math(int first_number, int second_number)
{
	switch (operation())
	{
	case 1: std::cout << first_number << " + " << second_number << " = " << first_number + second_number << std::endl; break;
	case 2: std::cout << first_number << " - " << second_number << " = " << first_number - second_number << std::endl; break;
	case 3: std::cout << first_number << " * " << second_number << " = " << first_number * second_number << std::endl; break;
	case 4: {
		if (!second_number) {
			std::cout << "На 0 делить нельзя!" << std::endl;
			return;
		}
		std::cout << first_number << " / " << second_number << " = " << first_number / second_number << std::endl;
		break;
	}
	case 5:{
		int sum{1};
		for (int i = 0; i < second_number; i++)
			sum *= first_number;
		std::cout << first_number << " в степени " << second_number << " = " << sum << std::endl;
		break;
	}
	default:
		std::cout << "Такой операции нет" << std::endl;
	}

}