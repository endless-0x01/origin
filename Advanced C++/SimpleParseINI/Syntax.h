#pragma once
#include <string>
#include <iostream>
#include <map>
class Syntax
{
public:
	using inMap = std::map<std::string, std::string>;
	using outMap = std::map<std::string, inMap>;

	Syntax() = default;

	void get_data(std::string& str);
	void show_data();

	outMap& take_map_data() {
		return ini;
	}

	void test() {
		for (auto& key : ini) {
			std::cout << key.first << ":\n";
			for (auto& val : key.second) {
				std::cout << val.first << " : " << val.second << std::endl;
			}
		}
	}

private:
	bool search_for_errors(const std::string& str);
	bool rules_for_section(const std::string& str);
	bool rules_for_value(const std::string& str);
	bool check_varibale( std::string& str);
	bool check_value(std::string& str);
	std::string data;
	outMap ini;

	std::string last_section;
	int n_lines{};
};

