#pragma once
#include "Figure.h"
#include "MyExceptions.h"

class Quadrilateral : public Figure
{
protected:
	struct sides_
	{
		int a_{};
		int b_{};
		int c_{};
		int d_{};

		sides_() = default;
		sides_(int a, int b, int c, int d) : a_(a), b_(b), c_(c), d_(d) {}
		sides_(int data) : a_(data), b_(data), c_(data), d_(data) {}
		sides_(int in, int data) : a_(in), b_(data), c_(in), d_(data) {}
	}s;
	struct corners_
	{
		int A_{};
		int B_{};
		int C_{};
		int D_{};

		corners_() = default;
		corners_(int a, int b, int c, int d) : A_(a), B_(b), C_(c), D_(d) {}
		corners_(int data) : A_(data), B_(data), C_(data), D_(data) {}
		corners_(int in, int data) : A_(in), B_(data), C_(in), D_(data) {}
	}c;

	virtual bool check_figure() const;
public:
	Quadrilateral(std::string name = "четырехугольник") : Figure(4, name) {}
	Quadrilateral(sides_ sides, corners_ corners, std::string name);

	FIGURELIBRARY_API void data_sides() const override;
	FIGURELIBRARY_API void print_info() const override;
};