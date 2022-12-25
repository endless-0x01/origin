#pragma once
#include <string>

#ifdef RACINGDYNAMICLIB_EXPORT
#define RACINGLIB_API __declspec(dllexport)
#else
#define RACINGLIB_API __declspec(dllimport)
#endif // RACINGLIB_API


class Transport
{
private:
	std::string _name_ts;
	int _speed{};
	double _time_racing{};
	enum class type_racing {
		land_transport = 1,
		air_transport,
		all_transport
	}_type_racing;

public:
	RACINGLIB_API Transport(std::string name_ts, int speed, type_racing type);

	RACINGLIB_API std::string get_name_ts() ;
	RACINGLIB_API double& get_time();
	RACINGLIB_API int get_speed();
	RACINGLIB_API type_racing get_type_racing();
	RACINGLIB_API type_racing set_type_racing(int type);
	RACINGLIB_API virtual void count_time_racing(int distance) = 0;


};

