#include <iostream>
#include <string>
#include <fstream>

class Address
{
private:
	std::string _city;
	std::string _street;
	int _num_home{};
	int _num_flat{};
public:
	Address() = default;
	Address(std::string city, std::string street, int nh, int nf) :
		_city(city), _street(street), _num_home(nh), _num_flat(nf) {}

	void out_data_file(std::ofstream& out) {
		out << _city << ", " << _street << ", " << _num_home << ", " << _num_flat << std::endl;
	}
	
	std::string get_city() {
		return _city;
	}
};

void sort_arr(Address* address, const int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			if (address[i].get_city() < address[j].get_city()) {
				Address temp = address[i];
				address[i] = address[j];
				address[j] = temp;
			}
		}
	}
}

int main()
{
	std::ifstream in("D:\\netology\\Lessons 4\\AddressCL\\in.txt");
	if (in.fail()) {
		std::cout << "Fail opened file!" << std::endl;
		exit(-1);
	}

	int rows{};
	in >> rows;
	Address *address = (Address*)operator new (sizeof(Address) * rows);
	for (int i = 0; i < rows; i++)
	{
		std::string city;
		in >> city;
		std::string street;
		in >> street;

		int nh{};
		in >> nh;

		int nf;
		in >> nf;

		new(&address[i]) Address(city, street, nh, nf);
	}

	std::ofstream out("data.txt");
	out << rows << std::endl;
	sort_arr(address, rows);
	for (int i = 0; i < rows; i++)
	{
		address[i].out_data_file(out);
	}

	in.close();
	return 0;
}