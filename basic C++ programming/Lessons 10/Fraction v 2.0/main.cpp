#include <iostream>
#include <string>

class Fraction
{
private:
	int numerator_;
	int denominator_;

	void check_cut(int& n, int& d) 
	{
		int max = n > d ? n : d;

		int max_devide{};

		for (int i = 1; i <= max; i++)
		{
			if (((n % i) == 0) && ((d % i) == 0))
			{
				max_devide = i;
			}
		}

		if (max_devide)
		{
			n /= max_devide;
			d /= max_devide;
		}
	}

public:
	Fraction() = default;
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	std::string print()
	{
		std::string str = std::to_string(numerator_) + "/" + std::to_string(denominator_);
		return str;
	}
	std::string print(Fraction frc)
	{
		std::string str = std::to_string(frc.numerator_) + "/" + std::to_string(frc.denominator_);
		return str;
	}

	bool operator==(Fraction& frc)
	{
		return numerator_ / denominator_ == frc.numerator_ / frc.denominator_ ? true : false;
	}

	bool operator!=(Fraction& frc)
	{
		return numerator_ / denominator_ != frc.numerator_ / frc.denominator_ ? true : false;
	}

	bool operator<(Fraction& frc)
	{
		return static_cast<double>(numerator_ / denominator_) < static_cast<double>(frc.numerator_ / frc.denominator_) ? true : false;
	}

	bool operator>(Fraction& frc)
	{
		return numerator_ / denominator_ > frc.numerator_ / frc.denominator_ ? true : false;
	}

	bool operator<=(Fraction& frc)
	{
		return numerator_ / denominator_ <= frc.numerator_ / frc.denominator_ ? true : false;
	}

	bool operator>=(Fraction& frc)
	{
		return numerator_ / denominator_ >= frc.numerator_ / frc.denominator_ ? true : false;
	}

	Fraction operator+(Fraction& oth)
	{
		int n = numerator_ * oth.denominator_ + oth.numerator_ * denominator_;
		int d = denominator_ * oth.denominator_;

		check_cut(n, d);
		return Fraction(n, d);
	}
	Fraction operator-(Fraction& oth)
	{
		int n = numerator_ * oth.denominator_ - oth.numerator_ * denominator_;
		int d = denominator_ * oth.denominator_;
		check_cut(n, d);
		return Fraction(n, d);
	}

	Fraction operator*(Fraction& oth)
	{
		int n = numerator_ * oth.numerator_;
		int d = denominator_ * oth.denominator_;
		check_cut(n, d);
		return Fraction(n, d);
	}

	Fraction operator/(Fraction& oth)
	{
		int n = numerator_ * oth.denominator_;
		int d = denominator_ * oth.numerator_;
		check_cut(n, d);
		return Fraction(n, d);
	}

	Fraction operator++()
	{
		numerator_ = numerator_ + denominator_;
		return Fraction(numerator_, denominator_);
	}
	Fraction operator++(int)
	{
		int time_numenator = numerator_;
		numerator_ = numerator_ + denominator_;
		return Fraction(time_numenator, denominator_);
	}

	Fraction operator--()
	{
		numerator_ = numerator_ - denominator_;
		return Fraction(numerator_, denominator_);
	}
	Fraction operator--(int)
	{
		int time_numenator = numerator_;
		numerator_ = numerator_ - denominator_;
		return Fraction(time_numenator, denominator_);
	}

};

void data_input(int& n1, int& n2)
{
	static int count = 1;
	std::cout << "Введите числитель дроби " << count << ": ";
	std::cin >> n1;
	std::cout << "Введите знаменатель дроби " << count << ": ";
	std::cin >> n2;
	++count;
}

int main()
{
	setlocale(LC_ALL, "Ru");

	int n{};
	int d{};

	data_input(n, d);
	Fraction f1(n, d);

	data_input(n, d);
	Fraction f2(n, d);
	
	Fraction f3;


	std::cout << f1.print() << " + " << f2.print() << " = " << f3.print(f1 + f2) << std::endl;
	std::cout << f1.print() << " - " << f2.print() << " = " << f3.print(f1 - f2) << std::endl;
	std::cout << f1.print() << " * " << f2.print() << " = " << f3.print(f1 * f2) << std::endl;
	std::cout << f1.print() << " / " << f2.print() << " = " << f3.print(f1 / f2) << std::endl;
	std::cout << "++" << f1.print() << " * " << f2.print() << " = " << f3.print( ((f1++) * f2) ) << std::endl;


	++f1;
	std::cout << "++" << f1.print() << " * " << f2.print() << " = " << f3.print(f1 * f2) << std::endl;
	f1--;
	std::cout << "--" << f1.print() << " * " << f2.print() << " = " << f3.print(f1 * f2) << std::endl;
	return 0;
}