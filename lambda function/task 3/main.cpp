#include <iostream>
#include <vector>
#include <functional>


int main()
{
	setlocale(LC_ALL, "ru");

	std::vector<double> angles{ 30 * 3.1415926 / 180, 60 * 3.1415926 / 180, 90 * 3.1415926 / 180 };
	

	std::vector<std::function<void(double)>> functions
	{
		[](double angle) { std::cout << "sin: " << std::sin(angle) << " ";  },
		[](double angle) { std::cout << "cos: " << std::cos(angle) << " ";  }
	};

	for (const auto& angle : angles)
	{
		std::cout << angle << ": ";
		for (const auto& function : functions) {
			function(angle);
		}
		std::cout << "\n";
	}

}