#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
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

};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}