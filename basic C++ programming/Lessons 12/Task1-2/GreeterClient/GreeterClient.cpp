#include <iostream>
#include "Greeter.h"
#include "Leaver.h"

int main()
{
	Greeter obj;
	LeaverDynamic::Leaver lobj;
	std::cout << obj.greet("Gleb") << std::endl;
	std::cout << lobj.leave("Gleb") << std::endl;

	return 0;
}