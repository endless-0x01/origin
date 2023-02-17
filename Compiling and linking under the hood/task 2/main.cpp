#include <iostream>


// ошибка линвковки - компилятор не может понять какую функцию ему вызвать, решением будет 
// сделать объвления int func(int); либо перегрузка функции
int func(int a) {
	return a * a;
}
int func(int a)
{
	return a * a;
}

int main()
{
	// синтаксическая ошибка
	std::cout << Hello World!<< std::endl; // не хватает кавычек
	//std::cout << "Hello World!" << std::endl;

	// семантическая ошибка, так как i никогда не будет больше 10 
	for (int i = 0; i > 10; i++) // правильный вариант i < 10
	{
		std::cout << i << std::endl;
	}

	std::cout << func(4);


	return 0;
}