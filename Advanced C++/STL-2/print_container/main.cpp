#include <iostream>
#include <string>
#include <set>
#include <list>
#include <vector>
#include <algorithm>

template<typename T>
void print_container(T b, T e)
{
	std::for_each(b, e, [](auto data) {std::cout << data << " "; } );
	std::cout << "\n";
}

int main()
{
	std::set<std::string> test_set = { "one", "two", "three", "four" };
	print_container(test_set.begin(), test_set.end()); // four one three two. помните почему такой порядок? :)

	std::list<std::string> test_list = { "one", "two", "three", "four" };
	print_container(test_list.begin(), test_list.end()); // one, two, three, four

	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	print_container(test_vector.begin(), test_vector.end()); // one, two, three, four
	return 0;
}