#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>


class Syntax
{
public:
	using inMap = std::unordered_map<std::string, std::string>;
	using outMap = std::unordered_map<std::string, inMap>;

	Syntax() = default;

	void get_data(std::string& str);
	void show_data();

	template<typename T>
	T get_result(const std::string& key, const std::string& value)
	{
		if (typeid(T) != typeid(int) || typeid(T) != typeid(std::string) || typeid(T) != typeid(double)) 
		{
			throw std::invalid_argument("not implemented convertion");
		}
	}
	template<>
	std::string get_result(const std::string& key, const std::string& value)
	{
		auto result = ini.at("[" + key + "]").find(value);


		return result->second;
	}
	template<>
	double get_result(const std::string& key, const std::string& value)
	{
		auto result = ini.at("[" + key + "]").find(value);


		return atof(result->second.c_str());
	}
	template<>
	int get_result(const std::string& key, const std::string& value)
	{
		auto result = ini.at("[" + key + "]").find(value);


		return atoi(result->second.c_str());
	}

private:
	bool search_for_errors(const std::string& str);
	bool rules_for_section(const std::string& str);
	bool rules_for_value(const std::string& str);
	bool check_varibale(std::string& str);
	bool check_value(std::string& str);


	std::string data;
	outMap ini;

	std::string last_section;
	int n_lines{};
};
