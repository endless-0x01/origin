#include "trinagles.h"
#include "quadrilaterals.h"

void print_info(Figure* figure)
{
	figure->print_info();
	std::cout << "\n";
}

int main()
{
	setlocale(LC_ALL, "Ru");
	
	try {
#if 0
		RightTriangle fg({3,4,5 }, {30,60, 90 });
		print_info(&fg);

#else
		RightTriangle fg({ 3,4,5 }, { 40 ,60, 90 });
		print_info(&fg);
#endif
	}
	catch (MyExceptions& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}