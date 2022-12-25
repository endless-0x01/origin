#include "LandTransport.h"

LandTransport::LandTransport(std::string name_ts, int speed, int type) : 
	Transport(name_ts, speed, set_type_racing(type)) {}

void LandTransport::count_time_racing(int distance)
{

}