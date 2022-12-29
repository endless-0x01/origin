#include <iostream>
#include <string>

class Figure
{
protected:
	int number_of_sides_;
	std::string name_figure_;
protected:
	Figure(int i, std::string name_f = "Фигура")
	{
		number_of_sides_ = i;
		name_figure_ = name_f;
	}
public:
	Figure() : Figure(0) {}
	void show_number_of_size() const
	{
		std::cout << name_figure_ << ": " << number_of_sides_ << std::endl;
	}
};

class Triangle : public Figure
{
public:
	Triangle() : Figure(3, "Треугольник") {}
};


class Quadrilateral : public Figure
{
public:
	Quadrilateral() : Figure(4, "Четырёхугольник") {}
};

int main()
{
	setlocale(LC_ALL, "Ru");

	std::cout << "Количество сторон: \n";
	Figure figure;
	figure.show_number_of_size();

	Triangle triangle;
	triangle.show_number_of_size();

	Quadrilateral quadrilateral;
	quadrilateral.show_number_of_size();

	return EXIT_SUCCESS;
}