#include "Syntax.h"

bool Syntax::search_for_errors(const std::string& str)
{
	if (rules_for_value(str))
		return true;

	return false;
}

bool Syntax::rules_for_section(const std::string& str)
{
	if (str[0] != '[' && str[str.length()] != ']')
		return false;

	ini[str];
	last_section = str;
	return true;
}
bool Syntax::rules_for_value(const std::string& str)
{
	if (rules_for_section(str)) {
		return true;
	}

	std::string variable;
	std::string values;

	 if (std::isalpha(str[0])) {
		 bool next = false;
		 for (auto& s : str) {
			 if (s == '=') {
				 next = true;
				 continue;
			 }
			 if (s == ';')
				 break;
			 if (!next)
				 variable += s;
			 else if(next)
				 values += s;
		 }
	}

	 if (check_value(values) && check_varibale(variable)) {
		 ini.at(last_section)[variable] = values;

		 //std::cout << ini[last_section][variable] << std::endl;
		 return true;
	 }

	return false;
}
bool Syntax::check_varibale(std::string& str)
{
	str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
	if (isalpha(str[0])) {
		return true;
	}
	return false;
}

bool Syntax::check_value(std::string& str)
{
	for (auto& s : str)
	{
		if ((isalpha(s)) && ('0' <= s && s <= '9') ) 
		{
			return false;
		}
	}

	return true;
}



void Syntax::get_data(std::string& str)
{
	n_lines++;
	if (str != "" && (!search_for_errors(str))) {
		std::string exc = "wrong syntax in string: " + std::to_string(n_lines);
		throw std::invalid_argument(exc);
	}
	data = data + str + '\n';
}

void Syntax::show_data() {
	std::cout << data << std::endl;
}