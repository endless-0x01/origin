#pragma once
#include "mystdlib.h"

#ifdef FIGUREDYNAMICLIB_EXPORTS
#define FIGURELIBRARY_API __declspec(dllexport)
#else
#define FIGURELIBRARY_API __declspec(dllimport)
#endif

class Figure
{
private:
	int numbers_of_sides_;
	std::string name_of_figure_;
protected:
	Figure(int numbers_side, std::string name_figure = "������")
		:numbers_of_sides_(numbers_side), name_of_figure_(name_figure) {}
protected:
	std::string& set_of_name();
public:
	Figure() : Figure(0, "������") {}

	 int get_numbers_of_sides() const;

	 std::string get_of_name() const;

	 virtual void data_sides() const {};

	 virtual void print_info() const
	{
		std::cout << name_of_figure_ << ":\n";
		numbers_of_sides_ == 0 ? std::cout << "����������\n" : std::cout << "������������:\n";
		std::cout << "���������� ������: " << numbers_of_sides_ << std::endl;

	};
};
