#include "Caclulator.h"


int main()
{
	Calc cl;

	int n1{}, n2{};

	while (true)
	{
		std::cout << "Enter num1: ";
		while (std::cin >> n1) {
			if (cl.set_num1(n1)) {
				break;
			}
			std::cout << "Enter num1: ";
		}

		std::cout << "Enter num2: ";
		while (std::cin >> n2) {
			if (cl.set_num2(n2))
				break;
			std::cout << "Enter num2: ";
		}


		std::cout << "num1 +" << " num2 = " << cl.add() << std::endl;
		std::cout << "num1 -" << " num2 = " << cl.subtract_1_2() << std::endl;
		std::cout << "num2 -" << " num1 = " << cl.subtract_2_1() << std::endl;
		std::cout << "num1 *" << " num2 = " << cl.multiply() << std::endl;
		std::cout << "num1 /" << " num2 = " << cl.divide_1_2() << std::endl;
		std::cout << "num2 /" << " num1 = " << cl.divide_2_1() << std::endl;

			
	}
	return 0;
}