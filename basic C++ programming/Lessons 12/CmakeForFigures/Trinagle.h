#pragma once
#include "Figure.h"
#include "MyExceptions.h"


 class Triangle : public Figure
{
protected:
	struct sides_
	{
		int a_{};
		int b_{};
		int c_{};

		sides_() = default;
		sides_(int a, int b, int c) : a_(a), b_(b), c_(c) {}
		sides_(int data) : a_(data), b_(data), c_(data) {}
		sides_(int in, int data) : a_(in), b_(data), c_(in) {}
	}s;
	struct corners_
	{
		int A_{};
		int B_{};
		int C_{};

		corners_() = default;
		corners_(int a, int b, int c) : A_(a), B_(b), C_(c) {}
		corners_(int data) : A_(data), B_(data), C_(data) {}
		corners_(int in, int data) : A_(in), B_(data), C_(in) {}
	}c;

protected: // Функция проверки фигуры
	 virtual bool check_figure() const;
public:
	 Triangle(std::string name = "Треугольник") : Figure(3, name) {}
	 Triangle(sides_ sides, corners_ corners, std::string name);
	 void data_sides() const override;
	 void print_info() const override;
};
