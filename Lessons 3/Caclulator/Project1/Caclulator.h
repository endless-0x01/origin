#pragma once

#include <iostream>

class Calc
{
private:
	double num1{};
	double num2{};
public:
	Calc() = default;

	bool set_num1(int num);
	bool set_num2(int num);
	double add();
	double multiply();
	double subtract_1_2();
	double subtract_2_1();
	double divide_1_2(); 
	double divide_2_1();


};