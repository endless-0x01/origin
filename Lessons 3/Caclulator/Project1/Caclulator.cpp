#include "Caclulator.h"

bool Calc::set_num1(int num)
{
	num1 = num;
	return num != 0 ? true : false;
}

bool Calc::set_num2(int num)
{
	num2 = num;
	return num != 0 ? true : false;
}

double Calc::add()
{
	return num1 + num2;
}

double Calc::subtract_1_2()
{
	return num1 - num2;
}
double Calc::subtract_2_1()
{
	return num2 - num1;
}

double Calc::multiply()
{
	return num1 * num2;
}

double Calc::divide_1_2()
{
	return num1 / num2;
}

double Calc::divide_2_1()
{
	return num2 / num1;
}