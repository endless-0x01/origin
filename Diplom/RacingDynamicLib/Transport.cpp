#include "Transport.h"

Transport::Transport(std::string name_ts, int speed, type_racing type) :
	_name_ts(name_ts), _speed(speed), _type_racing(type) {}

 std::string Transport::get_name_ts()  {
	return _name_ts;
}

double& Transport::get_time() {
	return _time_racing;
}

Transport::type_racing Transport::get_type_racing()
{
	return _type_racing;
}
Transport::type_racing Transport::set_type_racing(int type)
{
	return static_cast<type_racing>(type);
}
int Transport::get_speed() {
	return _speed;
}