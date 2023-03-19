#include <iostream>
#include <vector>

template<typename T>
void move_vectors(std::vector<T>&& object, std::vector<T>& object2)
{
	object2 = object;
	object.clear();
}

int main()
{

	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;
	move_vectors(std::move(one), two);
	

	return 0;
}