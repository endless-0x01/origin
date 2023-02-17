#include <iostream>
// было объявлено пространство имен, я убрал, так как считаю это плохой практикой =)

struct point {
	double m_x;
	double m_y;
	point() = default;
	point(double x, double y) {
		m_x = x;
		m_y = y;
	}
}; // не было точки с запятой

void print_point(const point& point_object); // было два определения, сделал объявления

int main()
{
	// не понял зачем заводить не нужную переменную , когда ее можно объявить в цикле
	for (int i = 0; i < 5; i++)
	{
		point my_point(i, i * 2);
		print_point(my_point);
	}
}

void print_point(const point& point_object) {
	std::cout << "x:" << point_object.m_x << ", y: "
		<< point_object.m_y << std::endl;
}