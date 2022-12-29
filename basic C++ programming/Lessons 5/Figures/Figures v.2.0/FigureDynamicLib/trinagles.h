#pragma once
#include "Trinagle.h"
#include "MyExceptions.h"

class RightTriangle : public Triangle
{
public:
	RightTriangle(sides_ side, corners_ corners, std::string name = "������������� �����������") : Triangle(side, corners, name)
	{
		check_figure();
		if (c.C_ != 90) {
			data_sides();
			std::cout << get_of_name() << " �� �������!" << std::endl;
			throw MyExceptions("�������: ���� � �� ����� 90 ��������");
		}
	}
};

class IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle(sides_ side, corners_ cor, std::string name = "�������������� �����������") : Triangle(side, cor, name)
	{
		s = side;
		c = cor;
		check_figure();

	}

	FIGURELIBRARY_API bool check_figure() const override
	{
		int sum_cor = c.A_ + c.B_ + c.C_;
		if (s.a_ != s.c_) {
			data_sides();
			std::cout << get_of_name() << " �� �������!" << std::endl;
			throw MyExceptions("�������: ������� �� �����");
		}
		else if (!(c.A_ == c.C_ && sum_cor == 180)) {
			data_sides();
			std::cout << get_of_name() << " �� �������!" << std::endl;
			throw MyExceptions("�������: ����� ����� �� ����� 180 ��� ��� ���� �� �����!");
		}
		return true;
	}
};

 class EquilateralTriangle : public Triangle
{
public:
	EquilateralTriangle(sides_ side) : Triangle(side, { 60 }, "�������������� �����������")
	{
	}

	FIGURELIBRARY_API bool check_figure() const override
	{
		bool equal_corners = (c.A_ == 60 && c.B_ == 60 && c.C_ == 60);
		bool equal_sides = (s.a_ == s.c_ && s.c_ == s.b_ && s.b_ == s.a_);
		if (!equal_corners)
		{
			data_sides();
			std::cout << get_of_name() << " �� �������!" << std::endl;
			throw MyExceptions("�������: ���� �� �����");
		}
		else if (!equal_sides)
		{
			data_sides();
			std::cout << get_of_name() << " �� �������!" << std::endl;
			throw MyExceptions("�������: ������� �� �����");
		}
		return true;
	}
};
