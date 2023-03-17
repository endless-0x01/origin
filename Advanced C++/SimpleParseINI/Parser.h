#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Syntax.h"


class Parser
{
public:
	Parser(std::string name_file)
	{
		std::ifstream in{ name_file };
		if (!in.is_open())
			throw std::runtime_error{ "Failed opened file!" };

		for (std::string s; std::getline(in >> std::ws, s); )
		{
			if (s[0] != ';') {
				data.get_data(s);
			}
		}
		//data.show_data();
		//data.test();
	}


	template<typename T>
	T get_value(std::string section_variable)
	{
		std::string section;
		std::string variable;
		bool next = false;
		for (auto& s : section_variable) {

			if (s == '.') {
				next = true;
				continue;
			}
			else if (next)
			{
				variable += s;
			}
			else {
				section += s;
			}

		}

		


		auto var = data.take_map_data().at('[' + section + ']').find(variable);

		auto end_var = static_cast<T>(atoi(var->second.c_str()));

		return end_var;
	}


private:
	
	Syntax data;
};

