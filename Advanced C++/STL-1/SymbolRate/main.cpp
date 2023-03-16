#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

struct SymbolRate 
{
	using pair = std::pair<char, int>;
public:
	void operator()(std::string& data) {
		for (auto& ch : data) {
			map[ch]++;
		}
	}

	void show_symbol_rate() {
		sorted_map();
		for (auto& data : vec) {
			std::cout << data.first << ": " << data.second << std::endl;
		}
	}
private:
	
	void sorted_map() {
		std::copy(map.begin(),
			map.end(),
			std::back_inserter<std::vector<pair>>(vec));

		std::sort(vec.begin(), vec.end(),
			[](const pair& l, const pair& r) {
				if (l.second != r.second)
					return l.second > r.second;
				return l.first < r.first;
			});

	}
	std::vector<pair> vec;
	std::map<char, int> map;
}sr;


int main()
{
	std::string data;
	std::cout << "In: ";
	std::getline(std::cin, data);

	sr(data);
	sr.show_symbol_rate();

	return 0;
}