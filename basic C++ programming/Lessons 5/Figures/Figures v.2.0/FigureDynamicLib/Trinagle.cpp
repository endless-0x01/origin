#include "Trinagle.h"
#include "MyExceptions.h"

Triangle::Triangle(sides_ sides, corners_ corners, std::string name) : Triangle(name)
{
	s = sides;
	c = corners;
	check_figure();

}

bool Triangle::check_figure() const
{
	if ((get_of_name() == "Треугольник" || (get_of_name() == "Прямоугольный треугольник"))) {


		const int check_sides = 3;
		const int sum_corners = c.A_ + c.B_ + c.C_;
		if (!(s.a_ != s.b_ && s.b_ != s.c_ && s.c_ != s.a_))
		{
			data_sides();
			std::cout << get_of_name() << " не создана!" << std::endl;
			throw MyExceptions("Причина: есть одинаковые стороны");
		}
		else if (!((get_numbers_of_sides() == check_sides) && (sum_corners == 180)))
		{
			data_sides();
			std::cout << get_of_name() << " не создана!" << std::endl;
			throw MyExceptions("Причина: сумма углов не равна 180");

		}
	}
	return true;
}

void Triangle::print_info() const
{
	std::cout << get_of_name() << ":\n";
	std::cout << "Количество сторон: " << get_numbers_of_sides() << std::endl;
	check_figure() == true ? std::cout << "Правильная\n" : std::cout << "Неправильная\n";
	std::cout << "Стороны: a=" << s.a_ << " b=" << s.b_ << " c=" << s.c_ << std::endl;
	std::cout << "Углы: a=" << c.A_ << " b=" << c.B_ << " c=" << c.C_ << std::endl;
}

void Triangle::data_sides() const
{
	std::cout << "Стороны: a=" << s.a_ << " b=" << s.b_ << " c=" << s.c_ << std::endl;
	std::cout << "Углы: a=" << c.A_ << " b=" << c.B_ << " c=" << c.C_ << std::endl;
}