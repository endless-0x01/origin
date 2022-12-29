#include "Quadrilateral.h"
#include "MyExceptions.h"

Quadrilateral::Quadrilateral(sides_ sides, corners_ corners, std::string name) : Quadrilateral(name)
{
	s = sides;
	c = corners;
	check_figure();
}

bool Quadrilateral::check_figure() const
{
	const int check_sides = 4;
	const int sum_corners = c.A_ + c.B_ + c.C_ + c.D_;
	if (get_of_name() == "���������������") {
		if (s.a_ != s.b_ && s.b_ != s.c_ && s.c_ != s.d_ && s.d_ != s.a_)
		{
			if (!((get_numbers_of_sides() == check_sides) && (sum_corners == 360)))
			{
				data_sides();
				std::cout << get_of_name() << " �� �������!" << std::endl;
				throw MyExceptions("�������: ����� ����� �� ����� 360");

			}
		}
	}
	return true;
}

void Quadrilateral::print_info() const
{
	std::cout << get_of_name() << ":\n";
	std::cout << "���������� ������: " << get_numbers_of_sides() << std::endl;
	check_figure() == true ? std::cout << "����������\n" : std::cout << "������������\n";
	std::cout << "�������: a=" << s.a_ << " b=" << s.b_ << " c=" << s.c_ << " d=" << s.d_ << std::endl;
	std::cout << "����: a=" << c.A_ << " b=" << c.B_ << " c=" << c.C_ << " d=" << c.D_ << std::endl;
}

void Quadrilateral::data_sides() const
{
	std::cout << "�������: a=" << s.a_ << " b=" << s.b_ << " c=" << s.c_ << " d=" << s.d_ << std::endl;
	std::cout << "����: a=" << c.A_ << " b=" << c.B_ << " c=" << c.C_ << " d=" << c.D_ << std::endl;
}