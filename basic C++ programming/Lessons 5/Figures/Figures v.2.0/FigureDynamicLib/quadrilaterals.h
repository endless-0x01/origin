#pragma once
#include "Quadrilateral.h"

class Parallelogram : public Quadrilateral
{
public:
	Parallelogram(sides_ side, corners_ corner) : Quadrilateral(side, corner, "Параллелограмм")
	{
	}

	FIGURELIBRARY_API virtual bool check_figure() const override
	{
		bool equal_corners = (c.A_ == c.C_ && c.B_ == c.D_ && ((c.A_ + c.B_ + c.C_ + c.D_) == 360));
		bool equal_sides = (s.a_ == s.c_ && s.b_ == s.d_);

		if (!equal_corners)
		{
			data_sides();
			std::cout << get_of_name() << " не создана!" << std::endl;
			throw MyExceptions("Причина: сумма углов не равна 360");
		}
		else if (!equal_sides)
		{
			data_sides();
			std::cout << get_of_name() << " не создана!" << std::endl;
			throw MyExceptions("Причина: противоположные стороны не равны!");
		}
		return true;
	}
};

 class Rectangle : public Parallelogram
{
public:
	Rectangle(sides_ side) : Parallelogram(side, { 90 })
	{
		set_of_name() = "Прямоугольник";
	}
	Rectangle(sides_ side, corners_ corners) : Parallelogram(side, corners)
	{
		set_of_name() = "Прямоугольник";
	}
	FIGURELIBRARY_API virtual bool check_figure() const override
	{
		bool equal_corners = (c.A_ == 90 && c.B_ == 90 && c.C_ == 90 && c.D_ == 90);
		bool equal_sides = (s.a_ == s.c_ && s.b_ == s.d_);
		if (!equal_corners) {
			data_sides();
			std::cout << get_of_name() << " не создана!" << std::endl;
			throw MyExceptions("Причина: углы не равны 90 градусов");
		}
		else if (!equal_sides)
		{
			data_sides();
			std::cout << get_of_name() << " не создана!" << std::endl;
			throw MyExceptions("Причина: Противоложные стороны не равны");
		}
		return true;
	}
};


FIGURELIBRARY_API class Rhombus : public Parallelogram
{
public:
	Rhombus(sides_ side, corners_ corners) : Parallelogram(side, corners)
	{
		set_of_name() = "Ромб";
	}

	virtual bool check_figure() const override
	{
		bool equal_corners = (c.A_ == c.C_ && c.B_ == c.D_ && ((c.A_ + c.B_ + c.C_ + c.D_) == 360));
		bool equal_sides = (s.a_ == s.c_ && s.b_ == s.d_ && s.a_ == s.b_ && s.d_ == s.a_);
		if (!equal_corners) {
			data_sides();
			std::cout << get_of_name() << " не создана!" << std::endl;
			throw MyExceptions("Причина: сумма углов не равна 360 градусов");
		}
		else if (!equal_sides)
		{
			data_sides();
			std::cout << get_of_name() << " не создана!" << std::endl;
			throw MyExceptions("Причина: Не все стороны  равны");
		}
		return true;
	}
};


FIGURELIBRARY_API class Square : public Rhombus
{
public:
	Square(sides_ side) : Rhombus(side, { 90 })
	{
		set_of_name() = "Квадрат";
	}

	virtual bool check_figure() const override
	{
		bool equal_corners = (c.A_ == 90 && c.B_ == 90 && c.C_ == 90 && c.D_ == 90);
		bool equal_sides = (s.a_ == s.c_ && s.b_ == s.d_ && s.a_ == s.b_ && s.d_ == s.a_);
		if (!equal_corners) {
			data_sides();
			std::cout << get_of_name() << " не создана!" << std::endl;
			throw MyExceptions("Причина: Не все углы равны 90 градусов");
		}
		else if (!equal_sides)
		{
			data_sides();
			std::cout << get_of_name() << " не создана!" << std::endl;
			throw MyExceptions("Причина: Не все стороны  равны");
		}
		return true;
	}
};