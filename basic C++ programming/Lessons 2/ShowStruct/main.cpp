#include <iostream>
#include <string>

struct data
{
	std::string city;
	std::string street;
	int n_home{};
	int n_flat{};
	int index{};

	data(std::string ct, std::string st, int nh, int nf, int in) :
		city(ct), street(st), n_home(nh), n_flat(nf), index(in) {}
};

void show_struct(data& st)
{
	std::cout << "City: " << st.city << std::endl;
	std::cout << "Street: " << st.street << std::endl;
	std::cout << "Number Home: " << st.n_home << std::endl;
	std::cout << "Number flat: " << st.n_flat << std::endl;
	std::cout << "Number index: " << st.index << std::endl;
}
int main()
{
	data d1("Moscow", "Arbat", 12, 8, 123456);
	data d2("Ighevsk", "Pushkina", 59, 143, 953769);

	show_struct(d1);
	std::cout << "--------------------------\n";
	show_struct(d2);
	return 0;
}