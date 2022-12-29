#pragma once
#include "mystdlib.h"
#include "Figure.h"


class MyExceptions : public std::domain_error
{
private:
	Figure figure;
public:
	MyExceptions(const char* str) : domain_error(str) {}
};